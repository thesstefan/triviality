#include "Question.h"

Question::Question() {
    this->setQuestion("EMPTY");

    this->setAnswer("EMPTY", 0);
    this->setAnswer("EMPTY", 1);
    this->setAnswer("EMPTY", 3);
    this->setAnswer("EMPTY", 3);

    this->setCorrectAnswerIndex(0);
}

QString Question::getQuestion() const {
    return this->question;
}

QString Question::getAnswer(int answerIndex) const {
    return this->answer[answerIndex];
}

int Question::getCorrectAnswerIndex() const {
    return this->correctAnswerIndex;
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

QString Question::getCorrectAnswer() const {
    return answer[correctAnswerIndex];
}
