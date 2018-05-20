#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QWidget>

#include <QLabel>

#include "PushButton.h"

class ScoreWidget : public QWidget {
    Q_OBJECT

    public:
        ScoreWidget(int score, QWidget *parent = 0);

        const PushButton *getCloseButton() const;

    private:
        QLabel *scoreLabel;

        PushButton *closeButton;

        PushButton *backButton;
};

#endif 
