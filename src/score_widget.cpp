#include "score_widget.h"

#include <QString>
#include <QVBoxLayout>

ScoreWidget::ScoreWidget(int score, QWidget *parent) : QWidget(parent) {
    this->setStyleSheet(
            "background-color: rgb(25, 25, 25);"
            "border: none;"
            "color: white;"
            "font-size: 120px;"
            );

    QString scoreString = QString::number(score);

    this->scoreLabel = new QLabel(scoreString, this);

    this->scoreLabel->setAlignment(Qt::AlignCenter);

    this->closeButton = new PushButton(this);

    this->closeButton->setText("CLOSE");

    this->backButton = new PushButton(this);

    this->backButton->setText("BACK");

    QVBoxLayout *buttonLayout = new QVBoxLayout();

    buttonLayout->addWidget(this->closeButton);
    buttonLayout->addWidget(this->backButton);

    QVBoxLayout *layout = new QVBoxLayout();

    layout->addWidget(this->scoreLabel);
    layout->addLayout(buttonLayout);

    layout->setAlignment(this->scoreLabel, Qt::AlignCenter);
    layout->setAlignment(buttonLayout, Qt::AlignCenter);

    this->setLayout(layout);
}

void connectCloseButton(QObject *receiver, const char *slot) {
    QObject::connect(this->closeButton, SIGNAL(clicked()), receiver, slot);
}

void connectBackButton(QObject *receiver, const char *slot) {
    QObject::connect(this->backButton, SIGNAL(clicked()), receiver, slot);
}
