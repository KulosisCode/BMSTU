TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        BaseIter.cpp \
        BaseVector.cpp \
        main.cpp

HEADERS += \
    BaseIter.h \
    BaseVector.h \
    ConstIterator.h \
    Error.h \
    Iterator.h \
    Vector.h \
    Vector.hpp
