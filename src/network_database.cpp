#include "network_database.h"

#include "exceptions.h"
#include "macros.h"

#include <QJsonArray>
#include <QJsonDocument>

const QString NetworkDatabase::TEST_QUERY = 
    QString("https://opentdb.com/api.php?amount=1&type=boolean");

NetworkDatabase::NetworkDatabase(const QString& serverQuery, QObject *parent) 
    : QObject(parent), Database(), networkRequest(QUrl(serverQuery)) {

    QObject::connect(&networkManager, &QNetworkAccessManager::finished,
                     this, &NetworkDatabase::onConnection);

    this->read();
}

NetworkDatabase::~NetworkDatabase() {}

void NetworkDatabase::read() {
    this->networkManager.get(this->networkRequest);
}

QString NetworkDatabase::decodeString(const QString& string) {
    return QUrl::fromPercentEncoding(string.toLatin1());
}

void NetworkDatabase::fillDatabase(const QJsonObject& JSON_data) {
    if (connectionError)
        throw ConnectionError("Connection Failed: " + std::to_string(connectionError));

    int responseCode = JSON_data[QString("response_code")].toInt(); 
    if (responseCode != 0)
        throw ConnectionError("Query Failed: " + std::to_string(responseCode));

    const QJsonArray array = JSON_data[QString("results")].toArray();

    for (QJsonValue field : array) {
        QJsonObject questionData = field.toObject();

        const QString correctAnswer = 
            this->decodeString(questionData[QString("correct_answer")].toString());

        // Test Connection
        if (correctAnswer == "True" || correctAnswer == "False")
            return;

        QList<QString> answers;
        answers.append(correctAnswer);

        for (QJsonValue incorrect_answer : (questionData[QString("incorrect_answers")].toArray()))
            answers.append(this->decodeString(incorrect_answer.toString()));

        Question question(this->decodeString(questionData[QString("question")].toString()), 0,
                          answers);

        this->data.append(question);
    }
}

void NetworkDatabase::setQuery(const QString& serverQuery) {
    this->networkRequest = QNetworkRequest(QUrl(serverQuery));
}

void NetworkDatabase::onConnection(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        this->networkManager.clearAccessCache();

        reply->deleteLater();

        connectionError = reply->error();
    } 

    this->fillDatabase(QJsonDocument::fromJson(reply->readAll()).object());
}

void NetworkDatabase::resetUsageTracker() {
    this->read();
}

void NetworkDatabase::connectionTest() {
    this->networkManager.get(QNetworkRequest(QUrl(TEST_QUERY)));
}
