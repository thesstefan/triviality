#include <QTextStream>
#include <QFile>

#include <QDebug>

#include "exceptions.h"
#include "file_database.h"

FileDatabase::FileDatabase(const QString& fileName) : Database() {
    this->file = new QFile(fileName);

    if (!this->file->exists())
        throw OpenFail("Could not open file: the file does not exist");

    if (file->open(QIODevice::ReadOnly) == false) {
        QString errorMsg = "Could not open file: " + this->file->errorString();
        throw OpenFail(errorMsg.toStdString());
    }

    this->stream = new QTextStream(this->file);

    try {
        this->readAll();
    } catch (const Exception& exception) {
        throw;
    }
}

FileDatabase::~FileDatabase() {
    delete this->stream;

    this->file->close();

    delete this->file;
}

void FileDatabase::addEntry(const QString& question, int correctAnswerIndex, const QList<QString>& answers) {
    Question entry;

    entry.setQuestion(question);
    entry.setCorrectAnswerIndex(correctAnswerIndex);

    for (int answerIndex = 0; answerIndex < ANSWERS_NUMBER; answerIndex++)
        entry.setAnswer(answers.at(answerIndex), answerIndex);

    this->data.append(entry);
}

void FileDatabase::read() {
    QString question = this->stream->readLine();

    if (question == "")
        throw EntryReadFail("Could not read entry.");

    char newline;

    int correctAnswerIndex = -1;

    *(this->stream) >> correctAnswerIndex >> newline;

    if (correctAnswerIndex < 0 || correctAnswerIndex > 3)
        throw EntryReadFail("Cold not read entry.");

    QList<QString> answers;

    for (int answerIndex = 0; answerIndex < ANSWERS_NUMBER; answerIndex++) {
        QString input = stream->readLine();

        if (input == "")
            throw EntryReadFail("Could not read entry.");

        answers.append(input);
    }

    *(this->stream) >> newline;

    this->addEntry(question, correctAnswerIndex, answers);
}

void FileDatabase::readAll() {
    while (this->stream->atEnd() == false) {
        try {
            read();
        } catch (const EntryReadFail& exception) {
            throw ReadFail("Could not read file.");
        }
    }
}
