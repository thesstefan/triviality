/**
 * @file quiz.h
 *
 * @brief This module provides the interface Quiz.
 */

#ifndef QUIZ_H
#define QUIZ_H

#include <QObject>

#include "main_window.h"

#include "game_controller.h"
#include "score_controller.h"
#include "menu_controller.h"

/** @brief The index of MenuWidget in the QStackedWidget. **/
const int MENU_INDEX = 0;

/** @brief The index of RoundWidget in the QStackedWidget. **/
const int GAME_INDEX = 1;

/** @brief The index of ScoreWidget in the QStackedWidget. **/
const int SCORE_INDEX = 2;

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
        /**
         * @brief The QStackedWidget containing the widgets used.
         */
        QStackedWidget *stack;

        /*
         * @brief The Database used for the Question extraction used in Game.
         */
        Database *data;

        /**
         * @brief The MainWindow which will be used to display other QWidgets.
         */
        MainWindow *window;

        /**
         * @brief The MenuController used to manage the menu display.
         */
        MenuController *menuController;

        /**
         * @brief The current Game instance.
         */
        GameController *gameController;

        /**
         * @brief The ScoreContoller used to manage the score display.
         */
        ScoreController *scoreController;

        /**
         * @brief Constructs the internal controllers used by Quiz.
         *
         * @param widget -> The QStackedWidget used to display the widgets.
         *
         * @param data -> The Database used to construct GameController instances.
         */
        void init(QStackedWidget *widget, Database *data);

    public:
        /**
         * @brief Destructs the Quiz.
         */
        ~Quiz();

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
        void closeApp();

    signals:
        void kill();
};

#endif
