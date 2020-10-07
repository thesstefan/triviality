/**
 * @file file_database.cpp
 *
 * This module provides the inteface of NetworkDatabase, derived of Database.
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
        const static QString TEST_QUERY;

        QNetworkAccessManager networkManager;
        QNetworkRequest networkRequest;


        /**
         * @brief Reads all the Question instances from the file.
         *
         * @exception ReadFail -> If the file is corrupted / not formatted properly.
         */
        void read();

        void fillDatabase(const QJsonObject& JSON_data);

        QString decodeString(const QString& string);

    private slots:
        void onConnection(QNetworkReply *reply);

    public:
        /**
         * @brief Constructs the NetworkDatabase and populates it by reading and parsing a text file.
         *
         * @param fileName -> The text file to read from.
         *
         * @exception OpenFail -> The file does not exist / can't be opened.
         */
        NetworkDatabase(const QString& serverQuery, QObject *parent = nullptr);

        void setQuery(const QString& serverQuery);

        void connectionTest();

        void resetUsageTracker();

        /**
         * @brief Default destructor
         */
        ~NetworkDatabase();
};

#endif
