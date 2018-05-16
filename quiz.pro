QT = widgets

SOURCES += src/main.cpp \
           src/Question.cpp \
           src/RoundWidget.cpp \
           src/RoundController.cpp \
           src/PushButton.cpp \
           src/database.cpp \
           src/file_database.cpp \
           src/Round.cpp \
           src/Game.cpp \
           src/MainWindow.cpp \
           src/ScoreWidget.cpp \
           src/exceptions.cpp

HEADERS += src/Question.h \
           src/RoundWidget.h \
           src/RoundController.h \
           src/PushButton.h \
           src/database.h \
           src/file_database.h \
           src/Round.h \
           src/Game.h \
           src/MainWindow.h \
           src/ScoreWidget.h \
           src/exceptions.h

RESOURCES += data/data.qrc

OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = data

TARGET = quiz

DEFINES += DEBUG
