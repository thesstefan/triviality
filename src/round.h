/**
 * @file round.h
 *
 * @brief This module provides the inteface of Round, essential part of Game.
 */

#ifndef ROUND_H
#define ROUND_H

#include <QObject>
#include <QStackedWidget>

#include "question.h"
#include "round_widget.h"
#include "main_window.h"

/**
 * @class Round
 *
 * @brief The class takes a Question and creates a RoundWidget, managing the connection
 * them.
 *
 * Round observes which PushButton from RoundWidget is pressed by the user.
 *
 * When a button is pressed, Round sees if the answer is correct or not and acts 
 * accordingly:
 *      @li Sets the color of the PushButton pressed to PushButton::CORRECT or PushButton::WRONG.
 *      @li Increments or not the score.
 */
class Round : public QObject {
    Q_OBJECT

    private:
        /**
         * @brief The Question managed by Round.
         */
        Question question;

        /**
         * @brief The RoundWidget managed by Round.
         */
        static RoundWidget *widget;

        /**
         * @brief The score achieved in the Round.
         *
         * If the user's answer is correct, the score is incremented by @ref ROUND_SCORE.
         *
         * Nothing happens otherwise.
         */
        int score;

        /**
         * @brief This method establishes the relation between the Question and the 
         * RoundWidget.
         */
        void sync();

    public:
        /**
         * @brief Constructs the round.
         *
         * @param question -> The question to be used.
         *
         * @param parent -> The QObject parent.
         */
        Round(const Question& question, QObject *parent = 0);

        /**
         * @brief Starts the round.
         *
         * The RoundWidget and the Question are now synced.
         *
         * The user is presented the question and the answers.
         *
         * The round ends when a button is pressed.
         */ 
        void start();

        /**
         * @brief Adds the RoundWidget to a QStackedWidget.
         *
         * @param stack -> The QStackedWidget to add to.
         */
        void addWidgetToStack(QStackedWidget *stack);

        /**
         * @brief Returns the score of the Round.
         */
        int getScore() const;

    public slots:
        /**
         * @brief Sees if the pressed PushButton in the RoundWidget is the one 
         * corespoding to the correct answer of Question and acts accordingly :
         *      @li Sets the color of the pressed PushButton to PushButton::CORRECT or PushButton::WRONG.
         *      @li Increments the score or not.
         *
         * This @b SLOT starts a timer which emits endRound().
         */
        void buttonClicked();

        /**
         * @brief This @b SLOT emits next().
         */
        void endRound();

    signals:
        /**
         * @brief This @b SIGNAL alerts the Game to switch to the next Round.
         */
        void next();
};

#endif
