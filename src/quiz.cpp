#include "quiz.h"

Quiz::Quiz(Database *data) {
    this->data = data;

    this->window = new MainWindow();

    this->menuController = new MenuController(this);

    this->menuController->connectButtons(this, SLOT(startGame()), SLOT(closeApp()));

    this->menuController->focus(this->window);
}

void Quiz::run() {
    this->window->show();
}

void Quiz::showScore(int score) {
    this->currentGame->deleteLater();
    
    this->scoreController = new ScoreController(score, this);

    this->scoreController->focus(this->window);

    this->scoreController->connectButtons(this, SLOT(back()), SLOT(closeApp()));
}

void Quiz::back() {
    this->scoreController->stopFocus(this->window);

    this->scoreController->deleteLater();

    this->menuController->focus(this->window);
}

void Quiz::startGame() {
    this->menuController->stopFocus(this->window);

    this->currentGame = new Game(this->data, this->window);

    QObject::connect(this->currentGame, SIGNAL(gameEnded(int)), this, SLOT(showScore(int)));

    this->currentGame->start();
}

void Quiz::closeApp() {
    this->window->hide();

    emit kill();
}

Quiz::~Quiz() {
    /*
    this->menuWidget->deleteLater();
    */

    this->window->deleteLater();
}
