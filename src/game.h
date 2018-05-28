#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QRandomGenerator>

#include "database.h"

#include "round.h"
#include "main_window.h"

class Game : public QObject {
    Q_OBJECT

    public:
        Game(Database *data, MainWindow *widget);

        void startNewRound();

        void start();

    public slots:
        void nextRound();

        void updateWindow();

        void deleteRound();

    private:
        Database *data;

        MainWindow *window;

        int roundsPassed;

        int score;

        QRandomGenerator *generator;

        Round *currentRound;

        void showScore();
};

#endif
