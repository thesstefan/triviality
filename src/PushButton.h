#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>

class PushButton : public QPushButton {
    Q_OBJECT

    public:
        PushButton(QWidget *parent = 0);

        void colorize(bool isCorrect);

        void clearColor();
};

#endif
