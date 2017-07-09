#-------------------------------------------------
#
# Project created by QtCreator 2016-11-14T20:26:47
#
#-------------------------------------------------


QT       += core gui network
QT       += gui
QT       += sql
QT        += widgets printsupport
 INCLUDEPATH  += /opt/local/mysql/include/mysql
 LIBS         += -L/opt/local/mysql/lib/mysql -lmysqlclient

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dexk
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    storesinformation.cpp \
    parametersetting.cpp \
    substation.cpp \
    dialog1.cpp \
    dialog2.cpp \
    dialog3.cpp \
    dialogclear.cpp \
    dialogstatistics.cpp \
    substation2.cpp \
    storeinformation1.cpp \
    storeinformation2.cpp \
    diastatisticsmana.cpp \
    diastatisticsmana1.cpp \
    diastatisticsmana2.cpp \
    zonghexinxixinshihuamian.cpp \
    screensaver.cpp \
    golobe.cpp \
    application.cpp \
    can.cpp \
    dialog.cpp \
    qsql_mysql.cpp \
    sql.cpp \
    store_information.cpp \
    Data_Management.cpp \
    Pressure_HD.cpp \
    Displacement_HD.cpp \
    realtime_presser.cpp \
    processer_storeinformation.cpp \
    Mapping/qcustomplot.cpp



HEADERS  += mainwindow.h \
    storesinformation.h \
    parametersetting.h \
    substation.h \
    dialog1.h \
    dialog2.h \
    dialog3.h \
    dialogclear.h \
    dialogstatistics.h \
    substation2.h \
    storeinformation1.h \
    storeinformation2.h \
    diastatisticsmana.h \
    diastatisticsmana1.h \
    diastatisticsmana2.h \
    zonghexinxixinshihuamian.h \
    screensaver.h \
    golobe.h \
    application.h \
    can.h \
    mythread.h \
    qsql_mysql.h \
    sql.h \
    store_information.h \
    main.h \
    Data_Management.h \
    Pressure_HD.h \
    Displacement_HD.h \
    Real-time_Data.h \
    realtime_presser.h \
    processer_storeinformation.h \
    Mapping/qcustomplot.h



FORMS    += mainwindow.ui \
    storesinformation.ui \
    parametersetting.ui \
    substation.ui \
    dialog1.ui \
    dialog2.ui \
    dialog3.ui \
    dialogclear.ui \
    dialogstatistics.ui \
    substation2.ui \
    storeinformation1.ui \
    storeinformation2.ui \
    diastatisticsmana.ui \
    diastatisticsmana1.ui \
    diastatisticsmana2.ui \
    zonghexinxixinshihuamian.ui \
    screensaver.ui \
    dialog.ui \
    sql.ui \
    store_information.ui \
    Data_Management.ui \
    Pressure_HD.ui \
    Displacement_HD.ui \
    realtime_presser.ui \
    processer_storeinformation.ui



RESOURCES += \
    pingbao.qrc

OTHER_FILES += \
    read.txt \
    problem.txt
