#include "question.h"

Question::Question(const QString& question, int correctAnswerIndex, QList<Question> answers) {
    this->setQuestion(question);

    for (int answerIndex = 0; answerIndex < ANSWERS_NUMBER; answerIndex++)
        this->setAnswer(answers.at(answerIndex), answerIndex);

    this->setCorrectAnswerIndex(correctAnswerIndex);
}

QString Question::getQuestion() const {
    return this->question;
}

QString Question::getAnswer(int answerIndex) const {
    return this->answer[answerIndex];
}

void Question::setQuestion(const QString& question) {
    this->question = question;
}

void Question::setAnswer(const QString& answer, int index) {
    this->answer[index] = answer;
}

void Question::setCorrectAnswerIndex(int index) {
    this->correctAnswerIndex = index;
}

bool Question::isCorrectAnswer(int answerIndex) const {
    return this->correctAnswerIndex == answerIndex;
}
