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
        this->read();
    } catch (const Exception& exception) {
        throw;
    }
}

FileDatabase::~FileDatabase() {
    delete this->stream;

    this->file->close();

    delete this->file;
}

void FileDatabase::readEntry() {
    QString question = this->stream->readLine();

    if (question == "")
        throw ReadFail("Could not read Question.");

    QString tempInput;

    bool convertionStatus = true;

    tempInput = this->stream->readLine();

    int correctAnswerIndex = tempInput.trimmed().toInt(&convertionStatus);

    if (correctAnswerIndex < 0 || correctAnswerIndex > 3)
        throw ReadFail("Cold not read Question.");

    QList<QString> answers;

    for (int answerIndex = 0; answerIndex < ANSWERS_NUMBER; answerIndex++) {
        tempInput = this->stream->readLine();

        if (tempInput == "")
            throw ReadFail("Could not read Question.");

        answers.append(tempInput);
    }

    this->stream->readLine();

    Question entry(question, correctAnswerIndex, answers);

    this->data.append(entry);
}

void FileDatabase::read() {
    while (this->stream->atEnd() == false) {
        try {
            this->readEntry();
        } catch (const Exception& exception) {
            QString errorMsg = QString("Could not read data : ") + QString(exception.what());

            throw ReadFail(errorMsg.toStdString());
        }
    }
}
