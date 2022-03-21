QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Heatmap.cpp \
    SingletonGenerator.cpp \
    f_4dim.cpp \
    f_crit.cpp \
    fletcher_reeves.cpp \
    grad_crit.cpp \
    iter_ctrit.cpp \
    main.cpp \
    chooseparams.cpp \
    opt_area.cpp \
    opt_function.cpp \
    opt_method.cpp \
    parallel.cpp \
    random_search.cpp \
    rosenbrok_f.cpp \
    sincos_f.cpp \
    sq_sum.cpp \
    stop_crit.cpp \
    vector_operations.cpp \
    x_crit.cpp

HEADERS += \
    Heatmap.h \
    SingletonGenerator.h \
    chooseparams.h \
    f_3dim.h \
    f_4dim.h \
    f_crit.h \
    fletcher_reeves.h \
    grad_crit.h \
    iter_ctrit.h \
    opt_area.h \
    opt_function.h \
    opt_method.h \
    parallel.h \
    random_search.h \
    rosenbrok_f.h \
    sincos_f.h \
    sq_sum.h \
    stop_crit.h \
    sup_struct.h \
    vector_operations.h \
    x_crit.h

FORMS += \
    chooseparams.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
