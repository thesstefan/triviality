#include <QTextStream>
#include <QFile>

#include "database.h"
#include "exceptions.h"

Database::Database(const QString& sourceName) {
    this->sourceName = sourceName;
}

Question Database::getQuestion(int questionIndex) const {
    return this->data.at(questionIndex);
}

void Database::markEntryUsed(int entryIndex) {
    this->entriesUsed.append(entryIndex);
}

bool Database::isEntryUsed(int entryIndex) const {
    return this->entriesUsed.contains(entryIndex);
}

int Database::size() const {
    return this->data.size();
}

void Database::write(const QString& outputFile) {
    QFile file(outputFile);

    if (file.open(QIODevice::WriteOnly) == false)
        throw OpenFail("Could not open output file in Database::write()");

    QTextStream out(&file);

    out << "Database size : " << this->data.size() << " Questions" << endl << endl;

    for (int entryIndex = 0; entryIndex < this->entries; entryIndex++) {
        Question question = this->data.at(entryIndex);

        out << question.getQuestion() << endl;

        out << question.getCorrectAnswerIndex() << endl;

        for (int answerIndex = 0; answerIndex < ANSWERS_NUMBER; answerIndex++)
            out << question.getAnswer(answerIndex) << endl;

        out << endl;
    }
}
