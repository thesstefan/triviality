/**
 * @file sql_database.h
 *
 * This module provides the inteface of SQL_LocalDatabase, derived of Database.
 *
 * SQL_LocalDatabase is the fallback for the online database, for when there is no internet
 * connection or a customized database is needed.
 */

#ifndef SQL_LOCALDATABASE_H
#define SQL_LOCALDATABASE_H

#include "database.h"

#include <QSqlDatabase>
#include <QSqlQuery>

class SQL_LocalDatabase : public Database {
    private:
        /** @brief The SQL driver to be used. (default = QSQLITE) **/ 
        const static QString DRIVER;

        /** 
         * @brief The query to be used for extracting general questions.
         *        (default question category)
         */
        const static QString GENERAL_QUESTION_QUERY;

        /** @brief The query string **/
        QString queryString;

        /** @brief The query used to extract questions. */
        QSqlQuery query;

        /** @brief The emulated internal SQL database. */
        QSqlDatabase db;

        /**
         * @brief Reads ROUNDS_NUMBER from the local SQL database.
         *
         * @exception @ref ReadError on read / connection error.
         */
        void read();

        /**
         * @brief Reads one question from the local SQL database.
         *
         * @exception @ref ReadError on read / connection error.
         */
        void readEntry();

    public:
        /**
         * @brief Constructs the SQL_LocalDatabase and creates the necessary connections.
         *
         * @note The constructor also starts the query and populates the Database.
         *
         * @param queryString -> The query to be used.
         * @param databasePath -> The path to the local database.
         *
         * @exception @ref OpenFail or ReadFail on connection/read problems.
         */
        SQL_LocalDatabase(const QString& databasePath, 
                          const QString& queryString = GENERAL_QUESTION_QUERY);

        /** @brief Changes the query string. **/
        void setQueryString(const QString& queryString);

        /**
         * @brief Default destructor
         */
        ~SQL_LocalDatabase();
};

#endif
