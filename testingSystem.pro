QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INLCUDEPATH += gui

SOURCES += \
    Admin.cpp \
    Config.cpp \
    Service.cpp \
    core/Admin.cpp \
    core/Config.cpp \
    core/Service.cpp \
    core/admin_manager.cpp \
    core/secure_manager.cpp \
    core/task_manager.cpp \
    core/test_manager.cpp \
    core/test_omnimanager.cpp \
    gui/adding_form.cpp \
    gui/admining.cpp \
    gui/admining_details.cpp \
    gui/auto_testing.cpp \
    gui/auto_testing_details.cpp \
    gui/hand_testing_details.cpp \
    gui/handtestingform.cpp \
    gui/login.cpp \
    gui/registration.cpp \
    gui/test_cases.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Admin.hpp \
    Config.hpp \
    core/Admin.hpp \
    core/Config.hpp \
    core/admin_manager.h \
    core/secure_manager.h \
    core/task_manager.h \
    core/test_manager.h \
    core/test_omnimanager.h \
    gui/adding_form.h \
    gui/admining.h \
    gui/admining_details.h \
    gui/auto_testing.h \
    gui/auto_testing_details.h \
    gui/hand_testing_details.h \
    gui/handtestingform.h \
    gui/login.h \
    gui/registration.h \
    gui/test_cases.h \
    mainwindow.h

FORMS += \
    gui/adding_form.ui \
    gui/admining.ui \
    gui/admining_details.ui \
    gui/auto_testing.ui \
    gui/auto_testing_details.ui \
    gui/hand_testing_details.ui \
    gui/handtestingform.ui \
    gui/login.ui \
    gui/registration.ui \
    gui/test_cases.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
