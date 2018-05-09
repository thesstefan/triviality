#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>

#include "PushButton.h"

class MainWidget : public QWidget {
    Q_OBJECT

    public:
        MainWidget(QWidget *parent = 0);

        const PushButton *getStartButton() const;
        const PushButton *getExitButton() const;

    private:
        PushButton *startButton;
        PushButton *exitButton;
};

#endif
