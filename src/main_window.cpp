#include "main_window.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->setStyleSheet(
            "background-color: rgb(25, 25, 25);"
            "border: none;"
            );

    this->setFixedSize(550, 600);

//    this->menuWidget = new MenuWidget(this);

//    QObject::connect(this->menuWidget->getStartButton(), SIGNAL(clicked()), this, SLOT(startButtonClicked()));

//    QObject::connect(this->mainMenu->getExitButton(), SIGNAL(clicked()), this, SLOT(close()));

//    this->setCentralWidget(this->mainMenuView);

    this->show();
}

/*
void MainWindow::startButtonClicked() {
    emit startGame();
}
*/
