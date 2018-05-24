#include "round.h"

#include <QTimer>

Round::Round(const Question& question, QObject *parent) : QObject(parent) {
    this->question = question;

    this->widget = new RoundWidget();

    this->controller = new RoundController(this->question, this->widget, this);

    QObject::connect(this->controller, SIGNAL(roundEnded(bool)), this, SLOT(end(bool)));
}

void Round::start() {
    this->controller->sync();

    emit windowNeedsUpdate();
}

void Round::end(bool isCorrect) {
    if (isCorrect)
        this->score += 10;

    this->widget->deleteLater();

    emit next();
}

int Round::getScore() const {
    return this->score;
}

RoundWidget *Round::getWidget() {
    return this->widget;
}
