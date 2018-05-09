#ifndef ROUNDCONTROLLER_H
#define ROUNDCONTROLLER_H

#include <QObject>

#include "Question.h"
#include "RoundWidget.h"

class RoundController : public QObject {
    Q_OBJECT

    public:
        RoundController(const Question& question, RoundWidget *widget, QObject *parent = 0);

        void sync();

    signals:
        void roundEnded(bool isCorrect);

    public slots:
        void buttonClicked();

        void endRound();

    private:
        bool isCorrect;

        Question question;

        RoundWidget *widget;
};

#endif
