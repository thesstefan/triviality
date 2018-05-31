#include "round.h"

#include <QTimer>

Round::Round(const Question& question, QObject *parent) : 
    QObject(parent), question(question), score(0) {

    this->widget = new RoundWidget();
}

void Round::sync() {
    this->widget->updateLabel(this->question.getQuestion());

    for (int buttonIndex = 0; buttonIndex < ANSWERS_NUMBER; buttonIndex++)
        this->widget->updateButton(this->question.getAnswer(buttonIndex), buttonIndex);

    this->widget->connectButtons(this, SLOT(buttonClicked()));
}

void Round::start() {
    this->sync();

    emit windowNeedsUpdate();
}

void Round::focusWidget(MainWindow *window) {
    window->setCentralWidget(this->widget);
}

int Round::getScore() const {
    return this->score;
}

void Round::buttonClicked() {
    QObject *sender = QObject::sender();

    PushButton *clickedButton = qobject_cast<PushButton *>(sender);

    if (clickedButton->text() == this->question.getCorrectAnswer()) {
        clickedButton->colorize(PushButton::CORRECT);

        this->score += ROUND_SCORE;
    } else 
        clickedButton->colorize(PushButton::WRONG);

    // Disable buttons to avoid multiple endRound() signals emitted.
    this->widget->disableButtons();

    // Wait 500ms before ending the Round.
    QTimer *timer = new QTimer(this);

    timer->setSingleShot(true);

    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(endRound()));

    timer->start(500);
}

void Round::endRound() {
    this->widget->deleteLater();

    emit next();
}
