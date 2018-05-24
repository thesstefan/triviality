#ifndef ROUNDWIDGET_H
#define ROUNDWIDGET_H

#include <QWidget>
#include <QLabel>

#include "push_button.h"

#define ANSWERS_NUMBER 4

class RoundWidget : public QWidget {
    Q_OBJECT

    private:
        QLabel *questionLabel;

        PushButton *answerButton[ANSWERS_NUMBER];

    public:
        RoundWidget(QWidget *parent = 0);

        void updateLabel(const QString& text);
        void updateButton(const QString& text, int index);
    
        const PushButton *getButton(int index) const;

        void disableButtons();
};

#endif
