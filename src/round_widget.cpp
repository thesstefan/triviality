#include <QWidget>

#include <QVBoxLayout>

#include "round_widget.h"

RoundWidget::RoundWidget(QWidget *parent) : QWidget(parent) {
    this->setStyleSheet(
            "background-color: rgb(25, 25, 25);"
            "border: none;"
            "color: white;"
            "font-size: 35px;"
            );

    this->questionLabel = new QLabel(this);

    this->questionLabel->setWordWrap(true);
    this->questionLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout *buttonLayout = new QVBoxLayout();

    for (int buttonIndex = 0; buttonIndex < ANSWERS_NUMBER; buttonIndex++) {
        this->answerButton[buttonIndex] = new PushButton(this);

        buttonLayout->addWidget(answerButton[buttonIndex]);
    }

    QVBoxLayout *mainLayout = new QVBoxLayout();

    mainLayout->addWidget(questionLabel);
    mainLayout->addItem(buttonLayout);

    mainLayout->setAlignment(questionLabel, Qt::AlignCenter);
    mainLayout->setAlignment(buttonLayout, Qt::AlignCenter);

    this->setLayout(mainLayout);
}

void RoundWidget::updateLabel(const QString& text) {
    this->questionLabel->setText(text);
}

void RoundWidget::updateButton(const QString& text, int index) {
    this->answerButton[index]->setText(text);
}

void RoundWidget::enableButtons(bool toEnable) {
    for (int buttonIndex = 0; buttonIndex < ANSWERS_NUMBER; buttonIndex++)
        this->answerButton[buttonIndex]->setEnabled(toEnable);
}

void RoundWidget::connectButtons(QObject *receiver, const char *slot) {
    for (int buttonIndex = 0; buttonIndex < ANSWERS_NUMBER; buttonIndex++)
        QObject::connect(this->answerButton[buttonIndex], SIGNAL(clicked()), receiver, slot);
}
