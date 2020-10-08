/**
 * @file file_database.cpp
 *
 * This module provides the inteface of NetworkDatabase, derived of Database.
 *
 * The modules makes queries to the Open Trivia Database and parses tparses the resulting
 * JSON.
 */

#ifndef NETWORK_DATABASE_H
#define NETWORK_DATABASE_H

#include "database.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

#include <QJsonObject>

class NetworkDatabase : public QObject, public Database {
    Q_OBJECT

    private:
        /**
         * @brief Used to circumvent the fact that slots can't throw exceptions.
         *        If connectionError is different than 0, then fillDatabase() throws
         *        a @ref ConnectionError
         */
        int connectionError = 0;

        /**
         * @brief The query used to test connection.
         *        It asks for a True/False question. (the game asks only for multiple choice)
         *        If the parser ecounters such a question, it knows that the request is just
         *        for a connection test.
         */         
        const static QString TEST_QUERY;

        /**
         * @brief The network manager used to manage connections.
         */
        QNetworkAccessManager networkManager;

        /**
         * @brief The request encapsulating the query to be made.
         */
        QNetworkRequest networkRequest;

        /**
         * @brief Triggers the data query, and on success, calls fillDatabase().
         *
         * @exception @ref ConnectionProblem or exceptions thrown by QNetworkManager.
         */
        void read();

        /**
         * @brief Parses the JSON data and fills the Database.
         *
         * @param JSON_data The JSON data to be parsed.
         *
         * @exception @ref ConnectionProblem on a query/slot connection fail.
         */
        void fillDatabase(const QJsonObject& JSON_data);

        /**
         * @brief Decodes string from URL386 enoding.
         *
         * @param string The string to be decoded.
         *
         * @return The decoded string.
         */
        QString decodeString(const QString& string);

    private slots:
        /**
         * @brief Called when the networkManager finishes the request.
         *
         * @exception Throws @ref ConnectionError on QNetworkReply on QNetworkReply error.
         */
        void onConnection(QNetworkReply *reply);

    public:
        /**
         * @brief Constructs the NetworkDatabase and creates the necessary connections.
         *
         * @note The constructor also starts the query and populates the Database.
         *
         * @param serverQuery -> The query to be used.
         *
         * @exception @ref ConnectionProblem on read errors.
         */
        NetworkDatabase(const QString& serverQuery, QObject *parent = nullptr);

        /**
         * @brief Updates the query string.
         *
         * @param serverQuery -> The new query string.
         */
        void setQuery(const QString& serverQuery);

        /**
         * @brief Checks connection with the server, by asking for a True/False question.
         *        (the game asks only for multiple choice so the parser knows it's just a test)
         */
        void connectionTest();

        /**
         * @brief Updates the database after an ended Round, by doing another query and 
         *        populating the Database with the new data.
         */
        void resetUsageTracker();

        /**
         * @brief Default destructor
         */
        ~NetworkDatabase();
};

#endif
