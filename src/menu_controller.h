/**
 * @file menu_controller.h
 *
 * @brief This module provides an interface for MenuController which stands as a 
 * controller between MenuWidget and Quiz.
 */

#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include <QObject>
#include <QStackedWidget>

#include "menu_widget.h"
#include "main_window.h"

#include "exceptions.h"

/**
 * @class MenuController
 *
 * @brief This class is used to manage the relation between MenuWidget and Quiz.
 *
 * It connects the buttons of MenuWidget to the coresponding slots of Quiz.
 *
 * It also can show the MenuWidget on the MainWindow.
 */
class MenuController : public QObject {
    Q_OBJECT

    private:
        /** @brief The MenuWidget to be managed. **/
        MenuWidget *widget;

    public:
        /**
         * @brief Constructs the MenuController.
         *
         * The MenuController also constructs the MenuWidget.
         *
         * @param parent -> The QObject parent of MenuController.
         */
        MenuController(bool online, QObject *parent = 0);

        /**
         * @brief Destructs the MenuController.
         *
         * This also destroys the internal MenuWidget. If focus() was used, 
         * stopFocus() is necessary before destructing.
         */
        ~MenuController();

        /**
         * @brief Sets MenuWidget as the central widget on MainWindow.
         *
         * @param window -> The MainWindow to be used.
         */
        void focus(MainWindow *window);

        /**
         * @brief Removes MenuWidget from MainWindow and gets the ownership back.
         *
         * @exception WidgetMismatch -> When the QWidget returned by MainWindow::takeCentralWidget() is 
         * not the one managed by MenuController.
         */
        void stopFocus(MainWindow *window);

        /**
         * @brief Connects the 2 PushButtons of MenuController to 2 slots.
         *
         * @param receiver -> The owner of the @b slots.
         *
         * @param startSlot -> The @b slot to be connected to the start PushButton.
         *
         * @param exitSlot -> The @b slot to be connected to the exit PushButton.
         */
        void connectButtons(QObject *receiver, const char *startSlot, const char *exitSlot);

        /**
         * @brief Adds the MenuWidget to a QStackedWidget.
         *
         * @param stack -> The QStackedWidget to add to.
         *
         * Note that Quiz needs the MenuWidget to be at index @ref MENU_INDEX in the QStackedWidget.
         */
        void addWidgetToStack(QStackedWidget *stack);
};

#endif
