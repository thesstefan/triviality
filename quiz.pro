QT = widgets

SOURCES += src/main.cpp \
           src/Question.cpp \
           src/RoundWidget.cpp \
           src/RoundController.cpp \
           src/PushButton.cpp \
           src/Database.cpp \
           src/Round.cpp \
           src/Game.cpp

HEADERS += src/Question.h \
           src/RoundWidget.h \
           src/RoundController.h \
           src/PushButton.h \
           src/Database.cpp \
           src/Round.h \
           src/Game.h

RESOURCES += data/data.qrc

OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = data

TARGET = quiz
