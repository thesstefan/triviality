#include <QTextStream>
#include <QFile>

#include "exceptions.h"
#include "file_database.h"

FileDatabase::FileDatabase(const QString& fileName) : Database(fileName) {}

void FileDatabase::addEntry(const QString& question, int correctAnswerIndex, const QList<QString>& answers) {
    Question entry;

    entry.setQuestion(question);
    entry.setCorrectAnswerIndex(correctAnswerIndex);

    for (int answerIndex = 0; answerIndex < ANSWERS_NUMBER; answerIndex++)
        entry.setAnswer(answers.at(answerIndex), answerIndex);

    this->data.append(entry);
}

void FileDatabase::readEntry(QTextStream& in) {
    QString question = in.readLine();

    if (question == "")
        throw EntryReadFail("Could not read entry.");

    char newline;

    int correctAnswerIndex = -1;

    in >> correctAnswerIndex >> newline;

    if (correctAnswerIndex < 0 || correctAnswerIndex > 3)
        throw EntryReadFail("Cold not read entry.");

    QList<QString> answers;

    for (int answerIndex = 0; answerIndex < ANSWERS_NUMBER; answerIndex++) {
        QString input = in.readLine();

        if (input == "")
            throw EntryReadFail("Could not read entry.");

        answers.append(input);
    }

    in >> newline;

    this->addEntry(question, correctAnswerIndex, answers);
}

void FileDatabase::read() {
    QFile file(this->fileName);

    if (file.open(QIODevice::ReadOnly) == false) 
        throw OpenFail("Could not open file.");

    QTextStream in(&file);

    while (in.atEnd() == false) {
        try {
            readEntry(in);
        } catch (const EntryReadFail& exception) {
            throw ReadFail("Could not read file.");
        }
    }
}
