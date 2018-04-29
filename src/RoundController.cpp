#include "RoundController.h"

RoundController::RoundController(const Question& question, RoundWidget *widget) {
    this->question = question;

    this->widget = widget;
}

RoundController::~RoundController() {}

void RoundController::sync() {
    this->widget->updateLabel(this->question.getQuestion());

    for (int buttonIndex = 0; buttonIndex < ANSWERS_NUMBER; buttonIndex++) {
        this->widget->updateButton(this->question.getAnswer(buttonIndex), buttonIndex);

        QObject::connect(this->widget->getButton(buttonIndex), SIGNAL(clicked()), this, SLOT(buttonClicked()));
    }
}

void RoundController::buttonClicked() {
    QObject *sender = QObject::sender();

    PushButton *clickedButton = qobject_cast<PushButton *>(sender);

    bool isCorrect = true;

    if (clickedButton != this->widget->getButton(this->question.getCorrectAnswerIndex()))
        isCorrect = false;

    clickedButton->colorize(isCorrect);

    emit roundEnded(isCorrect);
}
