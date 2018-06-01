#include "score_controller.h"

ScoreController::ScoreController(int score, QObject *parent) : QObject(parent) {
    this->widget = new ScoreWidget(score);
}

ScoreController::~ScoreController() {
    this->widget->deleteLater();
}

void ScoreController::updateScore(int score) {
    this->widget->updateScore(score);
}

void ScoreController::connectButtons(QObject *receiver, const char *backSlot, const char *closeSlot) {
    this->widget->connectBackButton(receiver, backSlot);

    this->widget->connectCloseButton(receiver, closeSlot);
}

void ScoreController::addWidgetToStack(QStackedWidget *stack) {
    stack->addWidget(this->widget);
}
