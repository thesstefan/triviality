#include "sql_database.h"

#include "macros.h"
#include "exceptions.h"

#include <QSqlError>
#include <QVariant>

const QString SQL_LocalDatabase::DRIVER
    ("QSQLITE");

const QString SQL_LocalDatabase::GENERAL_QUESTION_QUERY
    ("SELECT * FROM questionnaire ORDER BY RANDOM() LIMIT " + QString::number(ROUNDS_NUMBER));

SQL_LocalDatabase::SQL_LocalDatabase(const QString& databasePath,
                                     const QString& queryString) : 
    Database(), queryString(queryString) {

    if (QSqlDatabase::isDriverAvailable(SQL_LocalDatabase::DRIVER) == false)
        throw OpenFail("Not available SQL driver: " + SQL_LocalDatabase::DRIVER.toStdString());

    this->db = QSqlDatabase::addDatabase(SQL_LocalDatabase::DRIVER);
    this->db.setDatabaseName(databasePath);

    this->query = QSqlQuery(this->db);

    if (this->db.open() == false)
        throw OpenFail("SQL: " + db.lastError().text().toStdString());

    try {
        this->read();
    } catch (const Exception& exception) {
        throw exception;
    }
}

SQL_LocalDatabase::~SQL_LocalDatabase() {}

void SQL_LocalDatabase::setQueryString(const QString& queryString) {
    this->queryString = queryString;
}

void SQL_LocalDatabase::read() {
    if (this->query.prepare(this->queryString) == false)
        throw ReadFail("SQL: " + query.lastError().text().toStdString());

    if (!query.exec())
        throw ReadFail("SQL: " + query.lastError().text().toStdString());

    if (!query.first())
        throw ReadFail("SQL: Failed query" + query.lastError().text().toStdString());

    while (query.isValid()) {
        QString question_text = query.value("question_text").toString();
        QList<QString> answers;

        answers.append(query.value("correct_answer").toString());
        answers.append(query.value("incorrect_answer_1").toString());
        answers.append(query.value("incorrect_answer_2").toString());
        answers.append(query.value("incorrect_answer_3").toString());

        Question entry(question_text, 0, answers);

        this->data.append(entry);

        query.next();
    }
}
