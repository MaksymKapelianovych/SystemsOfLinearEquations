TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    jacobi.h \
    seidel.h \
    gauss.h \
    tridiagonalalgorithm.h
