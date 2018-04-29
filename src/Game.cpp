#include "Game.h"

#include <QTime>
#include <QThread>

#include <iostream>

Game::Game(Database *data, RoundWidget *widget) {
    this->data = data;
    this->widget = widget;

    this->score = 0;
    this->roundsPassed = 0;

    QTime time = QTime::currentTime();

    this->generator = new QRandomGenerator(time.hour() + time.minute() + time.second() + time.msec());
}

void Game::startNewRound() {
    Question question = this->data->getQuestion(this->generator->bounded(this->data->size()));

    this->currentRound = new Round(question, this->widget);

    QObject::connect(this->currentRound, SIGNAL(next()), this, SLOT(nextRound()));

    this->currentRound->start();
}

void Game::nextRound() {
    this->score += this->currentRound->getScore();

    this->roundsPassed += 1;

    if (this->roundsPassed < ROUNDS_NUMBER) {
        this->startNewRound();
    } else
        std::cout << this->roundsPassed << " -> " << this->score << std::endl;
}
