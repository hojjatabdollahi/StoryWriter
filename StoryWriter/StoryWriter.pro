#-------------------------------------------------
#
# Project created by QtCreator 2018-07-25T22:10:23
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = StoryWriter
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

#INCLUDEPATH += $$PWD/TextEdit
CONFIG += c++14

SOURCES += \
    Converters.cpp \
    main.cpp \
    MathOperationDataModel.cpp \
    ModuloModel.cpp \
    NumberDisplayDataModel.cpp \
    NumberSourceDataModel.cpp \
    TextEdit/highlighter.cpp \
    TextEdit/textedit.cpp \
    Panel/panel.cpp \
    Nodes/condition.cpp \
    Tools/convertor.cpp

HEADERS += \
    AdditionModel.hpp \
    Converters.hpp \
    DecimalData.hpp \
    DivisionModel.hpp \
    IntegerData.hpp \
    MathOperationDataModel.hpp \
    ModuloModel.hpp \
    MultiplicationModel.hpp \
    NumberDisplayDataModel.hpp \
    NumberSourceDataModel.hpp \
    SubtractionModel.hpp \
    TextEdit/highlighter.h \
    TextEdit/textedit.h \
    Panel/panel.h \
    Nodes/condition.h \
    Tools/convertor.h




#LIBS += -L../libnodes -lnodes
#INCLUDEPATH += $$PWD/../libnodes/include


#LIBS += -L/home/nexus/Projects/qt/build-Project-Desktop_Qt_5_11_1_GCC_64bit-Debug/libnodes/ -lnodes
#INCLUDEPATH += /home/nexus/Projects/qt/StoryWriter/libnodes/include/
#PRE_TARGETDEPS += /home/nexus/Projects/qt/build-Project-Desktop_Qt_5_11_1_GCC_64bit-Debug/libnodes/libnodes.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libnodes/release/ -lnodes
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libnodes/debug/ -lnodes
else:unix: LIBS += -L$$OUT_PWD/../libnodes/ -lnodes

INCLUDEPATH += $$PWD/../libnodes/include
DEPENDPATH += $$PWD/../libnodes/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libnodes/release/libnodes.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libnodes/debug/libnodes.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libnodes/release/nodes.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libnodes/debug/nodes.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../libnodes/libnodes.a

#LIBS += -L/home/nexus/Projects/qt/StoryWriter1/libnodes/build/ -lnodes
#INCLUDEPATH += /home/nexus/Projects/qt/StoryWriter1/libnodes/include/
#PRE_TARGETDEPS += /home/nexus/Projects/qt/StoryWriter1/libnodes/build/libnodes.a
