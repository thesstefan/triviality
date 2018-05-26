#include "question.h"

#include "exceptions.h"

Question::Question() {
    this->question = "EMPTY";

    this->correctAnswerIndex = 0;

    for (int answerIndex = 0; answerIndex < ANSWERS_NUMBER; answerIndex++)
        this->answer[answerIndex] = "EMPTY";
}

Question::Question(const QString& question, int correctAnswerIndex, const QList<QString>& answers) {
    this->question = question;

    if (correctAnswerIndex > ANSWERS_NUMBER || correctAnswerIndex < 0)
        throw OutOfBounds("Question::Question() -> correctAnswerIndex is out of bounds.");

    if (answers.size() != ANSWERS_NUMBER)
       throw OutOfBounds("Question::Question() -> answers.size() != ANSWERS_NUMBER"); 

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

void Question::read(QTextStream *inputStream) {
    this->question = inputStream->readLine();

    if (question == "")
        throw ReadFail("Could not read Question.");

    QString tempInput;

    bool convertionStatus = true;

    tempInput = inputStream->readLine();

    this->correctAnswerIndex = tempInput.trimmed().toInt(&convertionStatus);

    if (correctAnswerIndex < 0 || correctAnswerIndex > 3)
        throw ReadFail("Cold not read Question.");

    for (int answerIndex = 0; answerIndex < ANSWERS_NUMBER; answerIndex++) {
        tempInput = inputStream->readLine();

        if (tempInput == "")
            throw ReadFail("Could not read Question.");

        this->answer[answerIndex] = tempInput;
    }

    inputStream->readLine();
}

void Question::write(QTextStream *outputStream) const {
    (*outputStream) << this->getQuestion() << endl;

    (*outputStream) << "Correct Answers : " << this->getCorrectAnswer() << endl;

    for (int answerIndex = 0; answerIndex < ANSWERS_NUMBER; answerIndex++)
        (*outputStream) << this->getAnswer(answerIndex) << endl;

    (*outputStream) << endl;
}
