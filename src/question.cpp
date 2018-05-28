#include "question.h"

#include "exceptions.h"

Question::Question() {
    this->question = "EMPTY";

    for (int answerIndex = 0; answerIndex < ANSWERS_NUMBER; answerIndex++)
        this->answer[answerIndex] = "EMPTY";

    this->correctAnswerIndex = 0;
}

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
    if (answerIndex < 0 || answerIndex > ANSWERS_NUMBER)
        throw OutOfBounds("Question::getAnswer() -> index is out of bounds.");

    return this->answer[answerIndex];
}

QString Question::getCorrectAnswer() const {
    return this->answer[this->correctAnswerIndex];
}

bool Question::isCorrectAnswer(int answerIndex) const {
    return this->correctAnswerIndex == answerIndex;
}
