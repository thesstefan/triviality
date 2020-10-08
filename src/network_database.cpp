#include "network_database.h"

#include "exceptions.h"
#include "macros.h"

#include <QJsonArray>
#include <QJsonDocument>

NetworkDatabase::NetworkDatabase(const QUrl& serverQuery, QObject *parent) 
    : QObject(parent), Database(), networkController(serverQuery) {
    
    this->read();
 }

NetworkDatabase::~NetworkDatabase() {}

void NetworkDatabase::read() {
    this->networkController.executeRequest();

    int networkStatus = this->networkController.getStatus();
    QJsonObject jsonObject = this->networkController.getObject();

    if (networkStatus != 0 || jsonObject.isEmpty())
        throw ConnectionError("Connection Failed: " + std::to_string(networkStatus));

    this->fillDatabase(jsonObject);
}

QString NetworkDatabase::decodeString(const QString& string) {
    return QUrl::fromPercentEncoding(string.toLatin1());
}

void NetworkDatabase::fillDatabase(const QJsonObject& JSON_data) {
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

void NetworkDatabase::testConnection() {
    this->networkController.testConnection();

    const int controllerStatus = this->networkController.getStatus();
    if (controllerStatus != 0)
        throw ConnectionError("Connection Failed: " + std::to_string(controllerStatus));
}

void NetworkDatabase::resetUsageTracker() {
    this->read();
}
