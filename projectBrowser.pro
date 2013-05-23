HEADERS += \
    RightClick/rightclickmenu.h \
    RightClick/rectbutton.h \
    NavController/navcontroller.h \
    mainwindow.h \
    CustomWebView/customwebview.h \
    custompushbutton.h \
    RightClick/camembertbutton.h \
    CustomWebView/webviewmousetracking.h \
    CustomWebView/customtabwidget.h \
    ParamDialogBox/parametersdialogbox.h \
    NavController/favright.h \
    customwidget.h \
    NavController/navbar.h

SOURCES += \
    RightClick/rightclickmenu.cpp \
    RightClick/rectbutton.cpp \
    NavController/navcontroller.cpp \
    mainwindow.cpp \
    main.cpp \
    CustomWebView/customwebview.cpp \
    custompushbutton.cpp \
    RightClick/camembertbutton.cpp \
    CustomWebView/webviewmousetracking.cpp \
    CustomWebView/customtabwidget.cpp \
    ParamDialogBox/parametersdialogbox.cpp \
    NavController/favright.cpp \
    customwidget.cpp \
    NavController/navbar.cpp

QT += webkit

OTHER_FILES +=

RESOURCES += \
    icon.qrc

QMAKE_CXXFLAGS += -fpermissive #for using toStdString
