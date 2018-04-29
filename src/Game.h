#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QRandomGenerator>

#include "Database.h"

#include "Round.h"

#define ROUNDS_NUMBER 7

class Game : public QObject {
    Q_OBJECT

    public:
        Game(Database *data, RoundWidget *widget);

        void startNewRound();

    public slots:
        void nextRound();

    private:
        Database *data;

        RoundWidget *widget;

        int roundsPassed;

        int score;

        QRandomGenerator *generator;

        Round *currentRound;
};

#endif
