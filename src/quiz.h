/**
 * @file quiz.h
 *
 * @brief This module provides the interface Quiz.
 */

#ifndef QUIZ_H
#define QUIZ_H

#include <QObject>

#include "game.h"
#include "main_window.h"
#include "menu_widget.h"
#include "score_widget.h"

/**
 * @class Quiz
 *
 * @brief This is the class that controls evertything that happens in the program.
 *
 * It takes a Database which will be passed to Game.
 *
 * It creates a MainWindow and shows a MenuWidget on it.
 *
 * It lets the user press a button which:
 *      @li Closes the Quiz.
 *      @li Starts the Game.
 *
 * When the Game is ended, showScore is called, using a ScoreWidget to show the score.
 *
 * Again, the ScoreWidget lets the user to:
 *      @li Come back to the Main Menu.
 *      @li Close the Quiz.
 */
class Quiz : public QObject {
    Q_OBJECT

    private:
        /*
         * @brief The Database used for the Question extraction used in Game.
         */
        Database *data;

        /**
         * @brief The MainWindow which will be used to display other QWidgets.
         */
        MainWindow *window;

        /**
         * @brief The MenuWidget used to display the menu.
         */
        MenuWidget *menuWidget;

        /**
         * @brief The current Game instance.
         */
        Game *currentGame;

        /**
         * @brief The ScoreWidget used to display the score.
         */
        ScoreWidget *scoreWidget;

    public:
        /**
         * @brief Constructs the Quiz, assigning it a Database.
         *
         * @param data -> The Database to be used.
         */
        Quiz(Database *data);

        /**
         * @brief Runs the Quiz.
         *
         * This shows the MainWindow and the MenuWidget, starting the cycle explained.
         */
        void run();

    public slots:
        /**
         * @brief Starts the Game.
         *
         * This is called after the start button is pressed in MenuWidget.
         */
        void startGame();

        /**
         * @brief Shows the final score, using a ScoreWidget.
         *
         * This is called after the Game ends, when endGame() is emitted.
         */
        void showScore(int score);
    
        /**
         * @brief Goes back to the main menu.
         *
         * This is called after the back PushButton is pressed in ScoreWidget.
         */
        void back();

        /**
         * @brief Closes the Quiz.
         *
         * This is called when the quit PushButton is pressed in MenuWidget or ScoreWidget.
         */
        void close();
};

#endif
