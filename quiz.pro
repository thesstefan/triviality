QT = widgets

SOURCES += src/main.cpp \
           src/QuestionData.cpp \
           src/QuestionWindow.cpp \
           src/QuestionController.cpp \
           src/PushButton.cpp \
           src/MainMenu.cpp

HEADERS += src/QuestionData.h \
           src/QuestionWindow.h \
           src/QuestionController.h \
           src/PushButton.h \
           src/MainMenu.h

RESOURCES += data/data.qrc

OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = data

TARGET = quiz
