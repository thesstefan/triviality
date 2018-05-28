#include "quiz.h"

Quiz::Quiz(Database *data) {
    this->data = data;

    this->window = new MainWindow();

    this->menuWidget = new MenuWidget(this->window);

    this->window->setCentralWidget(this->menuWidget);

    this->menuWidget->connectStartButton(this, SLOT(startGame()));

    this->menuWidget->connectExitButton(this, SLOT(close()));
}

void Quiz::run() {
    this->window->show();
}

void Quiz::showScore(int score) {
    delete this->currentGame;
    
    this->scoreWidget = new ScoreWidget(score);

    this->window->setCentralWidget(this->scoreWidget);

    this->scoreWidget->connectBackButton(this, SLOT(back()));
    this->scoreWidget->connectCloseButton(this, SLOT(close()));
}

void Quiz::back() {
    this->window->setCentralWidget(this->menuWidget);

    //this->scoreWidget->deleteLater();
}

void Quiz::startGame() {
    this->currentGame = new Game(this->data, this->window);

    QObject::connect(this->currentGame, SIGNAL(gameEnded(int)), this, SLOT(showScore(int)));

    this->currentGame->start();
}

void Quiz::close() {
    this->window->hide();

    this->menuWidget->deleteLater();
    this->window->deleteLater();
    this->scoreWidget->deleteLater();
    this->currentGame->deleteLater();

    this->close();
}
