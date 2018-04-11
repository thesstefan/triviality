#ifndef QUESTIONWINDOW_H
#define QUESTIONWINDOW_H

#define ANSWERS_NUMBER 4

#include <QWidget>
#include <QLabel>

#include "PushButton.h"

class QuestionWindow : public QWidget {
    Q_OBJECT

    public:
        QuestionWindow(QWidget *parent = 0);

//    private:
        QLabel *questionLabel;

        PushButton *answerButton[ANSWERS_NUMBER];
};

#endif
