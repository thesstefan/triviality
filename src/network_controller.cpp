#include "network_controller.h"

#include <QJsonDocument>
#include <QNetworkReply>

const QUrl NetworkController::TEST_URL = 
    QUrl("https://opentdb.com/api.php?amount=1&type=boolean");

NetworkController::NetworkController(QObject *parent) 
    : QObject(parent) {
    
    QObject::connect(&manager, &QNetworkAccessManager::finished,
                     this, &NetworkController::onConnection);
}

NetworkController::NetworkController(const QUrl& requestURL, QObject *parent) 
    : QObject(parent), request(requestURL) {
    
    QObject::connect(&manager, &QNetworkAccessManager::finished,
                     this, &NetworkController::onConnection);
}

void NetworkController::setRequestURL(const QUrl& requestURL) {
    this->request = QNetworkRequest(requestURL);
}

void NetworkController::testConnection() {
    this->manager.get(QNetworkRequest(TEST_URL));
}

void NetworkController::executeRequest() {
    this->manager.get(this->request);
}

QJsonObject NetworkController::getObject() const {
    return this->jsonObject;
}

int NetworkController::getStatus() const {
    return this->status;
}

void NetworkController::onConnection(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        this->manager.clearAccessCache();

        reply->deleteLater();

        this->status = reply->error();
    } 

    this->jsonObject = QJsonDocument::fromJson(reply->readAll()).object();

    emit finished();
}
