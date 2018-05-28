#include <QWidget>

#include <QVBoxLayout>

#include "menu_widget.h"

MenuWidget::MenuWidget(QWidget *parent) : QWidget(parent) {
    this->setStyleSheet(
            "background-color: rgb(25, 25, 25);"
            "border: none;"
            );

    this->startButton = new PushButton(this);
    this->startButton->setText("START");

    this->exitButton = new PushButton(this);
    this->exitButton->setText("EXIT");

    QVBoxLayout *buttonLayout = new QVBoxLayout(this);

    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(exitButton);

    this->setLayout(buttonLayout);
}

void MenuWidget::connectStartButton(QObject *receiver, const char *slot) {
    QObject::connect(this->startButton, SIGNAL(clicked()), receiver, slot);
}

void MenuWidget::connectExitButton(QObject *receiver, const char *slot) {
    QObject::connect(this->exitButton, SIGNAL(clicked()), receiver, slot);
}
