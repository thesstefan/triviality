#include <QTextStream>
#include <QFile>

#include "exceptions.h"
#include "file_database.h"

FileDatabase::FileDatabase(const QString& fileName) : Database(fileName) {}

void FileDatabase::read() {
    QFile file(this->sourceName);

    if (file.open(QIODevice::ReadOnly) == false) 
        throw OpenFail("Could not open data file in FileDatabase::read()");

    QTextStream in(&file);

    char newline;

    // Used for better exception description.
    int lineIndex = 0;

    in >> this->entries >> newline >> newline;

    lineIndex += 2;

    for (int entryIndex = 0; entryIndex < this->entries; entryIndex++) {
        Question question;

        QString input = in.readLine();

        lineIndex++;

        if (input == "") {
            std::string message = "Question seems to be blank -> Line " + std::to_string(lineIndex) + ".";

            throw ReadFail(message);
        }

        question.setQuestion(input);

        int index;

        in >> index >> newline;

        lineIndex += 1;

        question.setCorrectAnswerIndex(index);

        for (int answerIndex = 0; answerIndex < ANSWERS_NUMBER; answerIndex++) {
            input = in.readLine();

            lineIndex++;

            if (input == "") {
                std::string message = "Answer " + std::to_string(answerIndex + 1) + " seems to be blank -> Line " + std::to_string(lineIndex) + ".";

                throw ReadFail(message);
            }

            question.setAnswer(input, answerIndex);
        }

        in >> newline;

        lineIndex++;

        this->data.append(question);
    }
}
