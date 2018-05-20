#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QList>

class Question {
    private:
        QString question;
        QString answer[ANSWERS_NUMBER];

        int correctAnswerIndex;

    public:
        Question(const QString& question, int correctAnswerIndex, const QList<QString>& answers);

        QString getQuestion() const;
        QString getAnswer(int answerIndex) const;

        void setQuestion(const QString& question);
        void setAnswer(const QString& answer, int index);
        void setCorrectAnswerIndex(int index);

        bool isCorrectAnswer(int answerIndex) const;
};

#endif
