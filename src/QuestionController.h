#ifndef QUESTIONCONTROLLER_H
#define QUESTIONCONTROLLER_H

#include <QObject>

#include "QuestionData.h"
#include "QuestionWindow.h"

class QuestionController : public QObject {
    Q_OBJECT

    public:
        QuestionController(QuestionData *questionData, QuestionWindow *window);

        void sync();

    public slots:
        void buttonClicked();

    private:
        QuestionData *questionData;

        QuestionWindow *window;
};

#endif
