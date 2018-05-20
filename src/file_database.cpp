#include <QTextStream>
#include <QFile>

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

void FileDatabase::read() {
    QString question = this->stream->readLine();

    if (question == "")
        throw EntryReadFail("Could not read entry.");

    QString tempInput;

    bool convertionStatus = true;

    tempInput = this->stream->readLine();

    int correctAnswerIndex = tempInput.trimmed().toInt(&convertionStatus);

    if (correctAnswerIndex < 0 || correctAnswerIndex > 3)
        throw EntryReadFail("Cold not read entry.");

    QList<QString> answers;

    for (int answerIndex = 0; answerIndex < ANSWERS_NUMBER; answerIndex++) {
        tempInput = this->stream->readLine();

        if (tempInput == "")
            throw EntryReadFail("Could not read entry.");

        answers.append(tempInput);
    }

    this->stream->readLine();

    Question entry(question, correctAnswerIndex, answers);

    this->data.append(entry);
}

void FileDatabase::readAll() {
    while (this->stream->atEnd() == false) {
        try {
            read();
        } catch (const EntryReadFail& exception) {
            throw ReadFail("Could not read file : Entry reading fail.");
        }
    }
}
