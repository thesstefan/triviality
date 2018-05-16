#include "Game.h"
#include "ScoreWidget.h"

#include <QTime>
#include <QThread>

#include <QTimer>

#include <iostream>

Game::Game(Database *data, MainWindow *window) {
    this->data = data;
    this->window = window;

    this->score = 0;
    this->roundsPassed = 0;

    QTime time = QTime::currentTime();

    this->generator = new QRandomGenerator(time.hour() + time.minute() + time.second() + time.msec());
}

void Game::updateWindow() {
    this->window->setCentralWidget(this->currentRound->getWidget());
}

void Game::showScore() {
    ScoreWidget *scoreWidget = new ScoreWidget(this->score);

    QObject::connect(scoreWidget->getCloseButton(), SIGNAL(clicked()), this->window, SLOT(close()));

    this->window->setCentralWidget(scoreWidget);
}

void Game::start() {
    this->startNewRound();
}

void Game::deleteRound() {
    this->currentRound->deleteLater();
}

void Game::startNewRound() {
    int questionIndex = this->generator->bounded(this->data->size());

    while (this->data->isEntryUsed(questionIndex))
        questionIndex = this->generator->bounded(this->data->size());

    Question question = this->data->getQuestion(questionIndex);

    this->data->markEntryUsed(questionIndex);

    this->currentRound = new Round(question);

    QObject::connect(this->currentRound, SIGNAL(windowNeedsUpdate()), this, SLOT(updateWindow()));

    QObject::connect(this->currentRound, SIGNAL(next()), this, SLOT(nextRound()));

    this->currentRound->start();
}

void Game::nextRound() {
    this->score += this->currentRound->getScore();

    this->roundsPassed += 1;

    if (this->roundsPassed < ROUNDS_NUMBER) {
        this->currentRound->deleteLater();

        this->startNewRound();
    } else
        showScore();
}