#include <QWidget>

#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>

#include "menu_widget.h"

const QColor ONLINE = QColor(20, 180, 50);
const QColor OFFLINE = QColor(200, 20, 20);

QString getColorString(bool online) {
    QString colorString = "rgb(%1, %2, %3);";
    const QColor networkColor(online ? ONLINE : OFFLINE);

    return colorString.arg(networkColor.red())
                      .arg(networkColor.green())
                      .arg(networkColor.blue());
}

QFrame *createNetworkLine(bool online) {
    const QString colorString(getColorString(online));

    QFrame *line = new QFrame();

    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    line->setStyleSheet(
            "background-color: " + colorString + ";"
    );
    line->setFixedHeight(5);

    return line;
}

QLabel *createNetworkLabel(bool online) {
    const QString colorString(getColorString(online));

    QLabel *label = new QLabel();
    label->setText(online ? "ONLINE" : "OFFLINE");
    label->setStyleSheet(
            "color: " + colorString + ";"
    );

    return label;
}

QVBoxLayout *createNetworkLayout(bool online) {
    QVBoxLayout *networkLayout = new QVBoxLayout();

    QLabel *networkLabel = createNetworkLabel(online);
    QFrame *networkLine = createNetworkLine(online);

    networkLayout->addWidget(networkLabel);
    networkLayout->addWidget(networkLine);

    networkLayout->setAlignment(networkLabel, Qt::AlignCenter);

    return networkLayout;
}

QVBoxLayout *MenuWidget::createButtonLayout() {
    this->startButton = new PushButton();
    this->startButton->setText("START");

    this->exitButton = new PushButton();
    this->exitButton->setText("EXIT");

    QVBoxLayout *buttonLayout = new QVBoxLayout();

    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(exitButton);

    return buttonLayout;
}

QVBoxLayout *MenuWidget::createMainLayout(bool online) {
    QVBoxLayout *buttonLayout = this->createButtonLayout();
    QVBoxLayout *networkLayout = createNetworkLayout(online);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    mainLayout->addLayout(buttonLayout);
    mainLayout->addLayout(networkLayout);

    mainLayout->setAlignment(buttonLayout, Qt::AlignCenter);

    mainLayout->setAlignment(networkLayout, Qt::AlignCenter);
    mainLayout->setAlignment(networkLayout, Qt::AlignBottom);

    return mainLayout;
}

MenuWidget::MenuWidget(bool online, QWidget *parent) : QWidget(parent) {
    this->setStyleSheet(
            "background-color: rgb(25, 25, 25);"
            "border: none;"
    );

    QVBoxLayout *mainLayout = this->createMainLayout(online);
    this->setLayout(mainLayout);
}

void MenuWidget::connectStartButton(QObject *receiver, const char *slot) {
    QObject::connect(this->startButton, SIGNAL(clicked()), receiver, slot);
}

void MenuWidget::connectExitButton(QObject *receiver, const char *slot) {
    QObject::connect(this->exitButton, SIGNAL(clicked()), receiver, slot);
}
