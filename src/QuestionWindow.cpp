#include <QWidget>

#include <QVBoxLayout>

#include "QuestionWindow.h"

QuestionWindow::QuestionWindow(QWidget *parent) : QWidget(parent) {
    setStyleSheet(
            "background-color: rgb(25, 25, 25);"
            "border: none;"
            "color: white;"
            "font-size: 35px;"
            );

    questionLabel = new QLabel(this);

    QVBoxLayout *buttonLayout = new QVBoxLayout();

    for (int buttonIndex = 0; buttonIndex < ANSWERS_NUMBER; buttonIndex++) {
        answerButton[buttonIndex] = new PushButton(this);

        buttonLayout->addWidget(answerButton[buttonIndex]);
    }

    QVBoxLayout *mainLayout = new QVBoxLayout();

    mainLayout->addWidget(questionLabel);
    mainLayout->addItem(buttonLayout);

    mainLayout->setAlignment(buttonLayout, Qt::AlignHCenter);
    mainLayout->setSpacing(50);

    setLayout(mainLayout);
}
