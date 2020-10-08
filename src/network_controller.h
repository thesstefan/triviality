/**
 * @file network_controller.h
 *
 * This module provides the interface of NetworkController.
 *
 * It manages requests to the OpenTDB server and receives the JSON data file.
 */

#ifndef NETWORKCONTROLLER_H
#define NETWORK_CONTROLLER_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonObject>

/**
 * @class NetworkController
 *
 * @brief Sends request to OpenTDB server, receives JSON data file.
 */
class NetworkController : public QObject {
    Q_OBJECT

    private:
        /** @class The request to be sent to the server. **/
       QNetworkRequest request;

       /**
        * @class The network manager that sends the request and
        *        receives the reply.
        */
       QNetworkAccessManager manager;

       /**
        * @brief The error-status of the connection.
        *        0 for success,
        *        reply error for anything else
        */
       int status;
       
       /** @brief The received JSON data. **/
       QJsonObject jsonObject;

    private slots:
        /** @brief Slot called on connection to the server (or error). **/
        void onConnection(QNetworkReply *reply);

    public:
        /** @brief The request URL to be used for connection testing. **/
        const static QUrl TEST_URL;

        /** @brief Default constructor **/
        NetworkController(QObject *parent = nullptr);

        /**
         * @brief Constructor using an URL
         *
         * @param requestURL -> The request to be sent to the server.
         */
        NetworkController(const QUrl& requestURL, QObject *parent = nullptr);

        /**
         * @brief Sets the request URL.
         *
         * @param requestURL -> The request to be sent to the server.
         */
        void setRequestURL(const QUrl& requestURL);

        /** @brief Returns the received JSON data. **/
        QJsonObject getObject() const;

        /** @brief Returns the connection error-status. **/
        int getStatus() const;

        /** @brief Executes the request. */
        void executeRequest();

        /** 
         * @brief Tests the connection.
         *        If successful, nothing happens
         *        Otherwise, the error status is changed.
         */ 
        void testConnection();
};

#endif
