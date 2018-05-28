#ifndef ROUND_H
#define ROUND_H

#include <QObject>

#include "question.h"
#include "round_widget.h"

class Round : public QObject {
    Q_OBJECT

    private:
        Question question;
        RoundWidget *widget;

        int score;

        void sync();

    public:
        Round(const Question& question, QObject *parent = 0);

        void start();

        void focusWidget(MainWindow *window);

        int getScore()

    public slots:
        void buttonClicked();
        void endRound();

    signals:
        void next();
        void windowNeedsUpdate();
};
