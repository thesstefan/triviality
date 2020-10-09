/**
 * @file menu_widget.h
 *
 * This file provides the interface of a customized QWidget, used to display the Main Menu in Quiz.
 */

#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include <QVBoxLayout>

#include "push_button.h"

/**
 * @class MenuWidget
 *
 * @brief The class is used to display the Main Menu in Quiz.
 *
 * It contains two buttons which allow the user to :
 *      @li Start the Game.
 *      @li Exit the App.
 */
class MenuWidget : public QWidget {
    Q_OBJECT

    private:
        /**
         * @brief The PushButton used to start the Game.
         */
        PushButton *startButton;

        /**
         * @brief The PushButton used to exit the App.
         */
        PushButton *exitButton;

        // Private implementation functions
        QVBoxLayout *createMainLayout(bool online);
        QVBoxLayout *createButtonLayout();

    public:
        /** @brief Color to use for the network status bar when ONLINE. **/
        const static QColor ONLINE;

        /** @brief Color to use for the network status bar when ONLINE. **/
        const static QColor OFFLINE;

        /**
         * @brief Constructs the MenuWidget.
         *
         * @param parent -> The QWidget parent.
         */
        MenuWidget(bool online, QWidget *parent = 0);

        /**
         * @brief Connects the start PushButton to a @b slot.
         *
         * @param receiver -> The QObject owner of the @b slot.
         *
         * @param slot -> The @b slot to connect with.
         */
        void connectStartButton(QObject *receiver, const char *slot);

        /**
         * @brief Connects the exit PushButton to a @b slot.
         *
         * @param receiver -> The QObject owner of the @b slot.
         *
         * @param slot -> The @b slot to connect with.
         */
        void connectExitButton(QObject *receiver, const char *slot);
};

#endif
