#ifndef QUESTIONDATA_H
#define QUESTIONDATA_H

#include <QString>

#define ANSWERS_NUMBER 4
#define QUESTIONS_NUMBER 4

class Question {
    private:
        QString question;
        QString answer[ANSWERS_NUMBER];

        int correctAnswerIndex;

        bool read();

    public:
        QuestionData();

        QString getQuestion() const;
        QString getAnswer(int answerIndex) const;

        bool isCorrectAnswer(int answerIndex) const;
        QString getCorrectAnswer() const;
};

#endif
