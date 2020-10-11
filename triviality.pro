QT += widgets network sql

SOURCES += src/main.cpp \
           src/menu_widget.cpp \
           src/push_button.cpp \
           src/question.cpp \
           src/database.cpp \
           src/file_database.cpp \
           src/network_database.cpp \
           src/network_controller.cpp \
           src/sql_database.cpp\
           src/exceptions.cpp \
           src/main_window.cpp \
           src/round.cpp \
           src/round_widget.cpp \
           src/score_widget.cpp \
           src/game.cpp \
           src/quiz.cpp \
           src/score_controller.cpp \
           src/menu_controller.cpp \
           src/game_controller.cpp

HEADERS += src/push_button.h \
           src/menu_widget.h \
           src/question.h \
           src/database.h \
           src/file_database.h \
           src/network_database.h \
           src/network_controller.h \
           src/sql_database.cpp \
           src/exceptions.h \
           src/main_window.h \
           src/round.h \
           src/round_widget.h \
           src/score_widget.h \
           src/game.h \
           src/quiz.h \
           src/score_controller.h \
           src/menu_controller.h \
           src/game_controller.h

RESOURCES += data/data.qrc

OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = data

TARGET = triviality

DEFINES += DEBUG
