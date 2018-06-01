#include "game_controller.h"

GameController::GameController(Database *data, QObject *parent) : QObject(parent), data(data) {
    this->createGame();
}

GameController::~GameController() {
    this->game->deleteLater();
}

void GameController::createGame() {
    this->game = new Game(this->data);

    QObject::connect(this->game, SIGNAL(gameEnded(int)), this, SLOT(endGame(int)));
}

void GameController::startGame() {
    this->game->start();
}

void GameController::addWidgetToStack(QStackedWidget *stack) {
    this->game->addWidgetToStack(stack);
}

void GameController::endGame(int score) {
    this->game->deleteLater();

    this->createGame();

    emit gameEnded(score);
}
