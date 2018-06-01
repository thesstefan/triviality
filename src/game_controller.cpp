#include "game_controller.h"

GameController::GameController(Database *data, QObject *parent) : QObject(parent), data(data) {}

void GameController::startGame() {
    this->game = new Game(this->data);

    QObject::connect(this->game, SIGNAL(gameEnded(int)), this, SLOT(endGame(int)));

    this->game->start()
}

void GameController::addWidgetToStack(QStackedWidget *stack) {
    this->game->addWidgetToStack(stack);
}

void GameController::endGame(int score) {
    this->game->deleteLater();

    emit gameEnded(score);
}
