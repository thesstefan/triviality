#include "question.h"

Question::Question(const QString& question, int correctAnswerIndex, const QList<QString>& answers) {
    this->question = question;

    for (int answerIndex = 0; answerIndex < ANSWERS_NUMBER; answerIndex++)
        this->answer[answerIndex] = answers.at(answerIndex);

    this->correctAnswerIndex = correctAnswerIndex;
}

QString Question::getQuestion() const {
    return this->question;
}

QString Question::getAnswer(int answerIndex) const {
    return this->answer[answerIndex];
}

QString Question::getCorrectAnswer() const {
    return this->answer[this->correctAnswerIndex];
}

bool Question::isCorrectAnswer(int answerIndex) const {
    return this->correctAnswerIndex == answerIndex;
}
