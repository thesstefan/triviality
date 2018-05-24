#include "round_controller.h"

#include <QTimer>

RoundController::RoundController(const Question& question, RoundWidget *widget, QObject *parent) : QObject(parent) {
    this->question = question;

    this->widget = widget;
}

void RoundController::sync() {
    this->widget->updateLabel(this->question.getQuestion());

    for (int buttonIndex = 0; buttonIndex < ANSWERS_NUMBER; buttonIndex++) {
        this->widget->updateButton(this->question.getAnswer(buttonIndex), buttonIndex);

        QObject::connect(this->widget->getButton(buttonIndex), SIGNAL(clicked()), this, SLOT(buttonClicked()));
    }
}

void RoundController::endRound() {
    emit roundEnded(this->isCorrect);
}

void RoundController::buttonClicked() {
    QObject *sender = QObject::sender();

    PushButton *clickedButton = qobject_cast<PushButton *>(sender);

    this->isCorrect = true;

    if (clickedButton != this->widget->getButton(this->question.getCorrectAnswerIndex()))
        this->isCorrect = false;

    clickedButton->colorize(this->isCorrect);

    // Disable buttons to avoid multiple endRound() signals emitted.
    this->widget->disableButtons();

    // Wait 500ms before ending the Round.
    QTimer *timer = new QTimer(this);

    timer->setSingleShot(true);

    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(endRound()));

    timer->start(500);
}
