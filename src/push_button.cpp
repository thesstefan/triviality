#include "push_button.h"

const QColor PushButton::DEFAULT = QColor(16, 16, 16);
const QColor PushButton::CORRECT = QColor(20, 180, 50);
const QColor PushButton::WRONG = QColor(200, 20, 20);

PushButton::PushButton(QWidget *parent) : QPushButton(parent) {
    this->setFlat(true);
    this->setFixedSize(500, 100);

    this->colorize(this->DEFAULT);
}

void PushButton::colorize(const QColor& color) {
    QString style = "background: rgb(%1, %2, %3);";

    style = style.arg(color.red()).arg(color.green()).arg(color.blue());
        
    style += "border: 1px solid #191919;";
    style += "color: white;";
    style += "font-size: 35px;";

    this->setStyleSheet(style);
}
