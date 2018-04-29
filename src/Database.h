#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QList>

#include "Question.h"

class Database {
    private:
        QList<Question> data;

        QString fileName;

        int entries;

    public:
        Database(const QString& fileName);

        int read();

        int write(const QString& fileName);

        Question getQuestion(int index) const;

        Question getRandomQuestion() const;

        int size() const;
};

#endif
