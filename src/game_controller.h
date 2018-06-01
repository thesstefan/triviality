/**
 * @file game_controller.h
 *
 * @brief This module provides the interface of GameController, used to manage the relationship between
 * Quiz and Game.
 */

#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <QObject>
#include <QStackedWidget>

#include "game.h"

/**
 * @class GameController
 *
 * @brief This class manages the connection between Quiz and Game.
 *
 * It manages the Game creation and it's also used to get the static RoundWidget in the QStackedWidget.
 */
class GameController : public QObject {
    Q_OBJECT

    private:
        /** @brief The Game managed. **/
        Game *game;

        /** @brief The Database used to construct the Game. **/
        Database *data;

    public:
        /**
         * @brief Constructs the GameController.
         *
         * @param data -> The Database used to create Game instances.
         *
         * @param parent -> The QObject parent.
         */
        GameController(Database *data, QObject *parent = 0);

        /**
         * @brief Creates and starts a Game.
         */
        void startGame();

        /**
         * @brief Calls addWidgetToStack on Round.
         */
        void addWidgetToStack(QStackedWidget *stack);

    public slots:
        /**
         * @brief Called when the Game ended.
         *
         * @param score -> The score of the ended Game.
         */
        void endGame(int score);

    signals:
        /**
         * @brief Announces Quiz that the Game ended.
         *
         * @param score -> The score of the ended Game.
         */
        void gameEnded(int score);
};

#endif
