#include "menu_controller.h"

MenuController::MenuController(QObject *parent) : QObject(parent) {
    this->widget = new MenuWidget();
}

MenuController::~MenuController() {
    this->widget->deleteLater();
}

void MenuController::focus(MainWindow *window) {
    window->setCentralWidget(this->widget);
}

void MenuController::stopFocus(MainWindow *window) {
    QWidget *temp = window->takeCentralWidget();

    if (temp != this->widget)
        throw WidgetMismatch("MenuController::stopFocus() -> Wrong QWidget from takeCentralWidget()");
}

void MenuController::connectButtons(QObject *receiver, const char *startSlot, const char *exitSlot) {
    this->widget->connectStartButton(receiver, startSlot);

    this->widget->connectExitButton(receiver, exitSlot);
}
