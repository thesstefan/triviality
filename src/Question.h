#ifndef QUESTION_H
#define QUESTION_H

#include <QString>

#define ANSWERS_NUMBER 4

class Question {
    private:
        QString question;
        QString answer[ANSWERS_NUMBER];

        int correctAnswerIndex;

    public:
        Question();

        QString getQuestion() const;
        QString getAnswer(int answerIndex) const;
        int getCorrectAnswerIndex() const;

        void setQuestion(const QString& question);
        void setAnswer(const QString& answer, int index);
        void setCorrectAnswerIndex(int index);

        bool isCorrectAnswer(int answerIndex) const;
        QString getCorrectAnswer() const;
};

#endif
