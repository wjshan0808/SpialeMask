## 详情帮助搜索qmake Manual下 Variables, Test Functions 关键字


TEMPLATE = app
#TARGET = SpialeMask

##
QT += gui
QT += core
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += console
CONFIG -= app_bundle
CONFIG -= c99
CONFIG += c11
QMAKE_CFLAGS -= -std=c99
QMAKE_CFLAGS += -std=c11


## UI中间文件输出目录
#UI_DIR += ../../Temp
#UI_HEADERS_DIR +=
#UI_SOURCES_DIR +=
## MOC中间文件输出目录
#MOC_DIR += ../../Temp
## QRC中间文件输出目录
#RCC_DIR += ../../Temp
## OBJ文件输出目录
#OBJECTS_DIR += ../../Temp


## 请在配置项目时修改Build目录
#
## Include目录(相对于Build目录)
INCLUDEPATH += ../../Include
# 编译提升依赖目录
DEPENDPATH += $$PWD
## Library目录(相对于Build目录)
LIBS += -L../../Library/ -lSpialeMask
## 执行文件输出目录(相对于Build目录)
DESTDIR += ../../Release


## 消息
#message("TARGET="$$TARGET)
#message("SUBDIRS="$$SUBDIRS)
#message("PWD="$$PWD)
#message("OUT_PWD="$$OUT_PWD)
#message("PRO_FILE_PWD="$$_PRO_FILE_PWD_)


## 程序图标
#RC_ICONS = $$_PRO_FILE_PWD_\sm.ico


##
SOURCES += \
    Core/Pages/Help.cpp \
    Core/Pages/Setting.cpp \
    Core/SpialeMaskGUI.cpp \
    Core/TitleBar.cpp \
    Core/TrcBar.cpp \
    Core/Viewer.cpp \
    Gui/Gui.cpp \
    Gui/Kit/Movable.cpp \
    main.cpp

HEADERS += \
    Core/Pages/Help.h \
    Core/Pages/Setting.h \
    Core/SpialeMaskGUI.h \
    Core/TitleBar.h \
    Core/TrcBar.h \
    Core/Viewer.h \
    Gui/Gui.h \
    Gui/Kit/Movable.h

FORMS += \
    Core/Pages/Help.ui \
    Core/Pages/Setting.ui \
    Core/SpialeMaskGUI.ui \
    Core/TitleBar.ui \
    Core/TrcBar.ui \
    Core/Viewer.ui

RESOURCES += \
    Style.qrc

DISTFILES +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



