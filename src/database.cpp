#include <QTextStream>
#include <QFile>

#include "database.h"
#include "exceptions.h"

Database::Database() {}

Database::~Database() {}

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

#ifdef DEBUG
void Database::write(const QString& outputFile) {
    QFile file(outputFile);

    if (file.open(QIODevice::WriteOnly) == false) {
        QString errorMsg = "Could not open output file : " + file.errorString();

        throw OpenFail(errorMsg.toStdString());
    }

    QTextStream out(&file);

    out << "Database Size : " << this->size() << " Questions" << endl << endl;

    for (int entryIndex = 0; entryIndex < this->size(); entryIndex++) {
        Question question = this->data.at(entryIndex);

        out << question.getQuestion() << endl;

        out << "Correct Answers : " << question.getCorrectAnswer() << endl;

        for (int answerIndex = 0; answerIndex < ANSWERS_NUMBER; answerIndex++)
            out << question.getAnswer(answerIndex) << endl;

        out << endl;
    }
}
#endif
