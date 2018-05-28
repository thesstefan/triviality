QT = widgets

SOURCES += src/main.cpp \
           src/menu_widget.cpp \
           src/push_button.cpp \
           src/question.cpp \
           src/database.cpp \
           src/file_database.cpp \
           src/exceptions.cpp \
           src/main_window.cpp \
           src/round.cpp \
           src/round_widget.cpp \
           src/score_widget.cpp \
           src/game.cpp \
           src/quiz.cpp

HEADERS += src/push_button.h \
           src/menu_widget.h \
           src/question.h \
           src/database.h \
           src/file_database.h \
           src/exceptions.h \
           src/main_window.h \
           src/round.h \
           src/round_widget.h \
           src/score_widget.h \
           src/game.h \
           src/quiz.h

RESOURCES += data/data.qrc

OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = data

TARGET = quiz

DEFINES += DEBUG
