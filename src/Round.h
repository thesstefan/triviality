#ifndef ROUND_H
#define ROUND_H

#include <QObject>

#include "Question.h"
#include "RoundController.h"
#include "RoundWidget.h"

class Round : public QObject {
    Q_OBJECT

    private:
        RoundController *controller;

        Question question;

        RoundWidget *widget;

        int score = 0;

    signals:
        void next();

    public slots:
        void end(bool isCorrect);

    public:
        Round(const Question& question, RoundWidget *widget);

        ~Round();

        void start();

        int getScore() const;
};

#endif
