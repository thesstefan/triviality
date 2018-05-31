#include "score_controller.h"

ScoreController::ScoreController(int score, QObject *parent) : QObject(parent) {
    this->widget = new ScoreWidget(score);
}

ScoreController::~ScoreController() {
    this->widget->deleteLater();
}

void ScoreController::focus(MainWindow *window) {
    window->setCentralWidget(this->widget);
}

void ScoreController::stopFocus(MainWindow *window) {
    QWidget *temp = window->takeCentralWidget();

    if (temp != this->widget)
        throw WidgetMismatch("ScoreController::stopFocus() -> Wrong QWidget from takeCentralWidget()");
}

void ScoreController::connectButtons(QObject *receiver, const char *backSlot, const char *closeSlot) {
    this->widget->connectBackButton(receiver, backSlot);

    this->widget->connectCloseButton(receiver, closeSlot);
}
