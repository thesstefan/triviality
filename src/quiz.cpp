#include "quiz.h"

Quiz::Quiz(Database *data) {
    this->data = data;

    this->window = new MainWindow();

    this->menuWidget = new MenuWidget(this->window);

    this->window->setCentralWidget(this->menuWidget);

    this->menuWidget->connectStartButton(this, SLOT(startGame()));

    this->menuWidget->connectExitButton(this, SLOT(closeApp()));
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

    this->window->setCentralWidget(this->menuWidget);

    this->menuWidget->show();
}

void Quiz::startGame() {
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
