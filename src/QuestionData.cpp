#include "QuestionData.h"

#include <QString>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>

bool QuestionData::read() {
    QFile file(":/data.txt");

    if (file.open(QIODevice::ReadOnly) == false) {
        QMessageBox::warning(0, "Could not open data file", file.errorString());

        readSuccess = false;

        return true;
    }

    QTextStream in(&file);

    question = in.readLine();

    if (question == "")
        return false;

    bool conversionSuccess = true;

    correctAnswerIndex = in.readLine().toInt(&conversionSuccess);

    if (conversionSuccess == false)
        return false;

    for (int index = 0; index < ANSWERS_NUMBER; index++) {
        answer[index] = in.readLine();

        if (answer[index] == "")
            return false;
    }

    return true;
}

QuestionData::QuestionData() {
    if (read() == false) {
        QMessageBox::warning(0, "Could not read question", "ERROR");

        readSuccess = false;
    }

    readSuccess = true;
}

bool QuestionData::isCorrectAnswer(int answerIndex) const {
    return correctAnswerIndex == answerIndex;
}

QString QuestionData::getCorrectAnswer() const {
    return answer[correctAnswerIndex];
}

QString QuestionData::getQuestion() const {
    return question;
}

QString QuestionData::getAnswer(int answerIndex) const {
    return answer[answerIndex];
}
