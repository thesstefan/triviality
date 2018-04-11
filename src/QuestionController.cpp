#include "QuestionController.h"

QuestionController::QuestionController(QuestionData *questionData, QuestionWindow *window) {
    this->questionData = questionData;
    this->window = window;
}

void QuestionController::sync() {
    window->questionLabel->setText(questionData->getQuestion());

    for (int buttonIndex = 0; buttonIndex < ANSWERS_NUMBER; buttonIndex++) {
        window->answerButton[buttonIndex]->setText(questionData->getAnswer(buttonIndex));

        QObject::connect(window->answerButton[buttonIndex], SIGNAL(clicked()), this, SLOT(buttonClicked()));
    }
}

void QuestionController::buttonClicked() {
    QObject *sender = QObject::sender();

    PushButton *clickedButton = qobject_cast<PushButton *>(sender);

    bool isCorrect = true;

    // TODO : Add error handling for when "clickedButton" is not one of the answerButtons
    
    if (clickedButton != window->answerButton[questionData->correctAnswerIndex])
        isCorrect = false;

    clickedButton->colorize(isCorrect);
}
