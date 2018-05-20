QT = widgets

SOURCES += src/main.cpp \
           src/question.cpp \
           src/database.cpp \
           src/file_database.cpp \
           src/exceptions.cpp

HEADERS += src/question.h \
           src/database.h \
           src/file_database.h \
           src/exceptions.h

RESOURCES += data/data.qrc

OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = data

TARGET = quiz

DEFINES += DEBUG
