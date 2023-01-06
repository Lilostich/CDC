QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -lcrypto
LIBS += -lssl
LIBS += -lconfig++

QMAKE_CXXFLAGS += -std=c++11

INLCUDEPATH += gui

SOURCES += \
    core/TaskLoader.cpp \
    core/Project.cpp \
    core/Secure.cpp \
    core/Admin.cpp \
    core/Config.cpp \
    core/Service.cpp \
#    core/admin_manager.cpp \
    core/file_manager.cpp \
#    core/secure_manager.cpp \
    core/task_manager.cpp \
    core/test_case.cpp \
    core/test_manager.cpp \
    core/test_omnimanager.cpp \
#    gui/adding_form.cpp \
    gui/admining.cpp \
    gui/admining_details.cpp \
#    gui/auto_testing.cpp \
#    gui/auto_testing_details.cpp \
    gui/change_password.cpp \
    gui/choice_tests.cpp \
    gui/edit_pass.cpp \
    gui/edit_test_case.cpp \
    gui/edit_tests_run_and_list.cpp \
    gui/hand_testing_details.cpp \
#    gui/handtestingform.cpp \
    gui/login.cpp \
    gui/registration.cpp \
    gui/report.cpp \
    gui/send_form.cpp \
    gui/test_cases.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    core/TaskLoader.hpp \
    core/Project.hpp \
    core/Secure.hpp \
    core/Base.hpp \
    core/Admin.hpp \
    core/Config.hpp \
    core/Options.h \
#    core/admin_manager.h \
    core/file_manager.h \
#    core/secure_manager.h \
    core/task_manager.h \
    core/test_case.h \
    core/test_manager.h \
    core/test_omnimanager.h \
#    gui/adding_form.h \
    gui/admining.h \
    gui/admining_details.h \
#    gui/auto_testing.h \
#    gui/auto_testing_details.h \
    gui/change_password.h \
    gui/choice_tests.h \
    gui/edit_pass.h \
    gui/edit_test_case.h \
    gui/edit_tests_run_and_list.h \
    gui/hand_testing_details.h \
#    gui/handtestingform.h \
    gui/login.h \
    gui/registration.h \
    gui/report.h \
    gui/send_form.h \
    gui/test_cases.h \
    mainwindow.h

FORMS += \
#    gui/adding_form.ui \
    gui/admining.ui \
    gui/admining_details.ui \
#    gui/auto_testing.ui \
#    gui/auto_testing_details.ui \
    gui/change_password.ui \
    gui/choice_tests.ui \
    gui/edit_pass.ui \
    gui/edit_test_case.ui \
    gui/edit_tests_run_and_list.ui \
    gui/hand_testing_details.ui \
#    gui/handtestingform.ui \
    gui/login.ui \
    gui/registration.ui \
    gui/report.ui \
    gui/send_form.ui \
    gui/test_cases.ui \
    mainwindow.ui

OTHER_FILES += TODO_LIST.txt

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
