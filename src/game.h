/**
 * @file game.h
 *
 * @brief This module provides the interface of Game, the most important element
 * of Quiz.
 */
#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QRandomGenerator>

#include "database.h"

#include "round.h"
#include "main_window.h"

/**
 * @class Game
 *
 * @brief This class extracts Question instances from a Database using a QRandomGenerator
 * and uses them to create @ref ROUNDS_NUMBER instances of Round, analyzing it's results.
 *
 * Game gets the score obtained by the user after @ref ROUNDS_NUMBER Round instances and 
 * tells Quiz the general score.
 */
class Game : public QObject {
    Q_OBJECT

    private:
        /**
         * @brief The Database used to extract the Question instances from.
         */
        Database *data;

        /**
         * @brief The number of Round instances that have passed.
         */
        int roundsPassed;

        /**
         * @brief The general score of the Game.
         */
        int score;

        /**
         * @brief The QRandomGenerator used to generate random questionId's for a 
         * better extraction of Question instances from the Database.
         */
        QRandomGenerator *generator;

        /**
         * @brief The current Round.
         */
        Round *currentRound;

    public:
        /**
         * @brief Constructs the Game.
         *
         * @param data -> The Database used for the Question extractions.
         */
        Game(Database *data);

        /**
         * @brief Starts a new Round.
         *
         * This method extracts a random Question of the Database and uses it
         * to create a new Round.
         */
        void startNewRound();

        /**
         * @brief Starts the Game.
         *
         * This method starts a new Round. It's equivalent to calling startNewRound().
         */
        void start();

        /**
         * @brief Calls addWidgetToStack() on the current RoundWidget.
         */
        void addWidgetToStack(QStackedWidget *widget);

    public slots:
        /**
         * @brief This @b SLOT creates a new Round and deletes the current one.
         *
         * It also increments the general score.
         *
         * If the number of rounds passed exceeds @ref ROUNDS_NUMBER, this emits gameEnded().
         */
        void nextRound();

        /**
         * @brief Deletes the Round.
         */
        void deleteRound();

    signals:
        /**
         * @brief Emitted when the Game is ended, telling Quiz the general score.
         */
        void gameEnded(int);
};

#endif
