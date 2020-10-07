#include <QApplication>

#include <QWidget>

#include "quiz.h"
#include "file_database.h"
#include "network_database.h"
#include "macros.h"

#include <iostream>

void run_quiz(Database &database, QApplication &app) {
    Quiz quiz(&database);

    QObject::connect(&quiz, SIGNAL(kill()), &app, SLOT(quit()));

    quiz.run();
}

int main(int argc, char *argv[]) {
    const QString 
        SERVER_QUERY("https://opentdb.com/api.php?type=multiple&encode=url3986&amount=" + 
                      QString::number(ROUNDS_NUMBER));

    QApplication app(argc, argv);

    NetworkDatabase online_database(SERVER_QUERY);
//    online_database.connectionTest();
/*
    try {
        online_database.connectionTest();

        run_quiz(online_database, app);
    
        Quiz quiz(&database);
        QObject::connect(&quiz, SIGNAL(kill()), &app, SLOT(quit()));
        quiz.run();
    } catch (const ConnectionError& exception) {
        
        qDebug() << exception.what();
*/
        FileDatabase local_database(":/data.txt");

        Quiz quiz(&online_database);
        QObject::connect(&quiz, SIGNAL(kill()), &app, SLOT(quit()));
        quiz.run();
//    }

    int ret = app.exec();

    std::cout << "SUCCESS" << std::endl;

    return ret;
}
