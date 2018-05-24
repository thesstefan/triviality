#include <QPushButton>

#include "push_button.h"

PushButton::PushButton(QWidget *parent) : QPushButton(parent) {
    this->setFlat(true);
    this->setFixedSize(500, 100);

    this->setStyleSheet(
            "background-color: rgb(16, 16, 16);"
            "border: 1px solid #191919;"
            "color: white;"
            "font-size: 35px;"
            );
}

void PushButton::colorize(bool isCorrect) {
    if (isCorrect)
        // Colorize the button Green if the answer is correct.
        this->setStyleSheet(
                "background-color: rgb(20, 180, 50);"
                "border: 1px solid #191919;"
                "color: white;"
                "font-size: 35px;"
                );
    else
        // Colorize the button Red if the answer is incorrect.
        this->setStyleSheet(
                "background-color: rgb(200, 20, 20);"
                "border: 1px solid #191919;"
                "color: white;"
                "font-size: 35px;"
                );
}

void PushButton::clearColor() {
    this->setStyleSheet(
            "background-color: rgb(16, 16, 16);"
            "border: 1px solid #191919;"
            "color: white;"
            "font-size: 35px;"
            );
}

