/**
 * @file score_widget.h
 *
 * This file provides a customized QWidget interface, used to show at the end of a Game.
 */

#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QWidget>

#include <QLabel>

#include "push_button.h"

/**
 * @class ScoreWidget
 *
 * @brief This class is used to show the score in Game.
 *
 * It also provides 2 buttons which are used to :
 *      @li Return to the Main Menu.
 *      @li Exit the app.
 */
class ScoreWidget : public QWidget {
    Q_OBJECT

    private:
        /**
         * @brief The QLabel which scores the score.
         */
        QLabel *scoreLabel;

        /**
         * @brief The PushButton used to close the app.
         */
        PushButton *closeButton;

        /**
         * The PushButton used to get back to the menu.
         */
        PushButton *backButton;

    public:
        /**
         * Constructs the ScoreWidget.
         *
         * @param score -> The score to be displayed.
         *
         * @param parent -> The QWidget parent.
         */
        ScoreWidget(int score, QWidget *parent = 0);

        /**
         * Updates the score in ScoreWidget.
         *
         * @param score -> The new score to be displayed.
         */
        void updateScore(int score);

        /**
         * Connect the close PushButton to a @b slot.
         *
         * @param receiver -> The QObject which owns the @b slot.
         *
         * @param slot -> The @b slot to connect with.
         */
        void connectCloseButton(QObject *receiver, const char *slot);

        /**
         * Connect the back PushButton to a @b slot.
         *
         * @param receiver -> The QObject which owns the @b slot.
         *
         * @param slot -> The @b slot to connect with.
         */
        void connectBackButton(QObject *receiver, const char *slot);
};

#endif 
