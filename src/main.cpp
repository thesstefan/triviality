#include <QApplication>
#include <QWidget>

#include "quiz.h"
#include "file_database.h"
#include "network_database.h"
#include "macros.h"

const QUrl 
    SERVER_QUERY("https://opentdb.com/api.php?type=multiple&encode=url3986&amount=" + 
                 QString::number(ROUNDS_NUMBER));

const QString
    LOCAL_DATABASE_PATH(":/data.txt");

std::unique_ptr<Database> databaseFactory() {
    try {
        std::unique_ptr<NetworkDatabase> onlineDatabase(new NetworkDatabase(QUrl(SERVER_QUERY)));
        onlineDatabase->testConnection();
        onlineDatabase->resetUsageTracker();

        return onlineDatabase;
    } catch (const Exception& exception) {
        qDebug() << exception.what() << Qt::endl;
    }

    try {
        std::unique_ptr<FileDatabase> localDatabase(new FileDatabase(LOCAL_DATABASE_PATH));

        return localDatabase;
    } catch (const Exception& exception) {
        qDebug() << exception.what() << Qt::endl;
    }

    return nullptr;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    std::unique_ptr<Database> database = databaseFactory();

    Quiz quiz(database.get());

    QObject::connect(&quiz, SIGNAL(kill()), &app, SLOT(quit()));

    int ret = app.exec();

    qDebug() << "SUCCESS";

    return ret;
}
