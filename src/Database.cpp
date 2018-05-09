#include <QMessageBox>
#include <QIODevice>
#include <QFile>
#include <QTextStream>

#include <iostream>

#include "Database.h"

#define FAIL 1
#define SUCCESS 0

Database::Database(const QString& fileName) {
    this->data = QList<Question>();

    this->entriesUsed = QList<int>();

    this->fileName = fileName;
}

int Database::read() {
    QFile file(this->fileName);

    if (file.open(QIODevice::ReadOnly) == false) {
        QMessageBox::warning(0, "Could not open data file", file.errorString());

        return FAIL;
    }

    QTextStream in(&file);

    char newline;

    in >> this->entries >> newline >> newline;

    for (int entryIndex = 0; entryIndex < this->entries; entryIndex++) {
        Question question;

        QString input = in.readLine();

        if (input == "")
            return FAIL;

        question.setQuestion(input);

        int index;

        in >> index >> newline;

        question.setCorrectAnswerIndex(index);

        for (int answerIndex = 0; answerIndex < ANSWERS_NUMBER; answerIndex++) {
            input = in.readLine();

            if (input == "")
                return FAIL;

            question.setAnswer(input, answerIndex);
        }

        in >> newline;

        this->data.append(question);
    }

    return SUCCESS;
}

int Database::write(const QString& fileName) {
    QFile file(fileName);

    if (file.open(QIODevice::WriteOnly) == false) {
        QMessageBox::warning(0, "Could not open write file", file.errorString());

        return FAIL;
    }

    QTextStream out(&file);

    out << "DATABASE SIZE : " << this->data.size() << " QUESTIONS" << endl << endl;

    for (int entryIndex = 0; entryIndex < this->entries; entryIndex++) {
        Question question = this->data.at(entryIndex);

        out << question.getQuestion() << endl;

        out << question.getCorrectAnswerIndex() << endl;

        for (int answerIndex = 0; answerIndex < ANSWERS_NUMBER; answerIndex++)
            out << question.getAnswer(answerIndex) << endl;

        out << endl;
    }

    return SUCCESS;
}

void Database::markEntryUsed(int entryIndex) {
    this->entriesUsed.append(entryIndex);
}

Question Database::getQuestion(int index) const {
    return this->data.at(index);
}

bool Database::isEntryUsed(int entryIndex) const {
    return this->entriesUsed.contains(entryIndex);
}

int Database::size() const {
    return this->data.size();
}
