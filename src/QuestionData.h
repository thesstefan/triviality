#ifndef QUESTIONDATA_H
#define QUESTIONDATA_H

#include <QString>

#define ANSWERS_NUMBER 4
#define QUESTIONS_NUMBER 4

class QuestionData {
    private:
        QString question;
        QString answer[ANSWERS_NUMBER];


        bool read();
        bool readSuccess;

    public:
        QuestionData();
        int correctAnswerIndex;

        QString getQuestion() const;
        QString getAnswer(int answerIndex) const;

        bool isCorrectAnswer(int answerIndex) const;
        QString getCorrectAnswer() const;
};

#endif
