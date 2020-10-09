#include "menu_controller.h"

MenuController::MenuController(bool online, QObject *parent) : QObject(parent) {
    this->widget = new MenuWidget(online);
}

MenuController::~MenuController() {
    this->widget->deleteLater();
}

void MenuController::connectButtons(QObject *receiver, const char *startSlot, const char *exitSlot) {
    this->widget->connectStartButton(receiver, startSlot);

    this->widget->connectExitButton(receiver, exitSlot);
}

void MenuController::addWidgetToStack(QStackedWidget *stack) {
    stack->addWidget(this->widget);
}
