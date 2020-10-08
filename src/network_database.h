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
#include "network_controller.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

#include <QJsonObject>

class NetworkDatabase : public QObject, public Database {
    Q_OBJECT

    private:
        /** 
         * @brief Controller that manages OpenTDB requests.
         */
        NetworkController networkController;

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
        NetworkDatabase(const QUrl& serverQuery, QObject *parent = nullptr);

        /**
         * @brief Checks if the network controller could connect to the server.
         */
        void testConnection();

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
