#ifndef ROUNDWIDGET_H
#define ROUNDWIDGET_H

#include <QWidget>
#include <QLabel>

#include "push_button.h"

class RoundWidget : public QWidget {
    Q_OBJECT

    private:
        QLabel *questionLabel;

        PushButton *answerButton[ANSWERS_NUMBER];

    public:
        RoundWidget(QWidget *parent = 0);

        void updateLabel(const QString& text);
        void updateButton(const QString& text, int index);
    
        void disableButtons();

        void connectButtons(QObject *receiver, const char* slot);
};

#endif
