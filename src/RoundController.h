#ifndef ROUNDCONTROLLER_H
#define ROUNDCONTROLLER_H

#include <QObject>

#include "Question.h"
#include "RoundWidget.h"

class RoundController : public QObject {
    Q_OBJECT

    public:
        RoundController(const Question& question, RoundWidget *widget);

        ~RoundController();

        void sync();

    signals:
        void roundEnded(bool isCorrect);

    public slots:
        void buttonClicked();

    private:
        Question question;

        RoundWidget *widget;
};

#endif
