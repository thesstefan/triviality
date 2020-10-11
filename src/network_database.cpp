#include "network_database.h"

#include "exceptions.h"
#include "macros.h"

#include <QJsonArray>
#include <QJsonDocument>

#include <QEventLoop>


NetworkDatabase::NetworkDatabase(const QUrl& serverQuery, QObject *parent) 
    : QObject(parent), Database(), networkController(serverQuery) {
    
//    this->read();
}

NetworkDatabase::~NetworkDatabase() {}

void NetworkDatabase::read() {
    this->networkController.executeRequest();

    QEventLoop loop;
    connect(&(this->networkController), SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    int networkStatus = this->networkController.getStatus();
    QJsonObject jsonObject = this->networkController.getObject();

    if (networkStatus != QNetworkReply::NoError || jsonObject.isEmpty())
        throw ConnectionError("Connection Failed: " + std::to_string(networkStatus));

    this->fillDatabase(jsonObject);
}

QString NetworkDatabase::decodeString(const QString& string) {
    return QUrl::fromPercentEncoding(string.toLatin1());
}

void NetworkDatabase::fillDatabase(const QJsonObject& JSON_data) {
    int responseCode = JSON_data[QString("response_code")].toInt(); 
    if (responseCode != QNetworkReply::NoError)
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

        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        auto rng = std::default_random_engine(seed);
        std::shuffle(answers.begin(), answers.end(), rng);

        const int correctAnswerIndex = answers.indexOf(correctAnswer);

        Question question(this->decodeString(questionData[QString("question")].toString()), 
                          correctAnswerIndex,
                          answers);

        this->data.append(question);
    }
}

void NetworkDatabase::testConnection() {
    this->networkController.testConnection();

    QEventLoop loop;
    connect(&(this->networkController), SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    int networkStatus = this->networkController.getStatus();
    QJsonObject jsonObject = this->networkController.getObject();

    if (networkStatus != QNetworkReply::NoError || jsonObject.isEmpty())
        throw ConnectionError("Connection Failed: " + std::to_string(networkStatus));

    this->fillDatabase(jsonObject);
}

void NetworkDatabase::resetUsageTracker() {
    this->read();
}
