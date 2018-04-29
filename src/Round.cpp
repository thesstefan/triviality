#include "Round.h"

Round::Round(const Question& question, RoundWidget *widget) {
    this->widget = widget;

    this->question = question;

    this->controller = new RoundController(this->question, this->widget);

    QObject::connect(this->controller, SIGNAL(roundEnded(bool)), this, SLOT(end(bool)));
}

Round::~Round() {
    delete this->controller;
}

void Round::start() {
    this->controller->sync();
}

void Round::end(bool isCorrect) {
    if (isCorrect)
        this->score += 10;

    emit next();
}

int Round::getScore() const {
    return this->score;
}
