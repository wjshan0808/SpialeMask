## 详情帮助搜索qmake Manual下 Variables, Test Functions 关键字

## 动态库
TEMPLATE = lib

DEFINES += SPIALEMASK_LIBRARY

CONFIG -= qt
CONFIG -= c99
#CONFIG += c1x
QMAKE_CFLAGS -= -std=c99
QMAKE_CFLAGS += -std=c1x


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
#DEPENDPATH += ../../Include
## Library目录(相对于Build目录)
#LIBS += -L../../Library/ -lpthread
## 执行文件输出目录(相对于Build目录)
DESTDIR += ../../Release


## Win编译链接前后执行事件
win* {
    #CONFIG(release, debug|release):QMAKE_PRE_LINK += $$quote()
    QMAKE_POST_LINK += $$quote($$_PRO_FILE_PWD_/QmakePostLink.bat $$replace(PWD, /, \\))
}
## Unix编译链接前后执行事件
unix {
    #CONFIG(release, debug|release):QMAKE_PRE_LINK += $$quote()
    QMAKE_POST_LINK += $$quote($$_PRO_FILE_PWD_/QmakePostLink.sh $$PWD)
}


## 消息
#message("TARGET="$$TARGET)
#message("PWD="$$PWD)
#message("OUT_PWD="$$OUT_PWD)
#message("PRO_FILE_PWD="$$_PRO_FILE_PWD_)


##
SOURCES += \
    App/App.c \
    App/Kit/Utility.c \
    App/Log/Log.c \
    Core/Cog.c \
    Core/CogChain.c \
    Core/Roulette.c \
    Core/Spiale.c \
    SpialeMask.c

HEADERS += \
    App/AppDefines.h \
    App/Kit/Utility.h \
    App/Log/Log.h \
    Core/Cog.h \
    Core/CogChain.h \
    Core/Roulette.h \
    Core/Spiale.h \
    SpialeMask.h

DISTFILES += \
    QmakePostLink.bat \
    QmakePostLink.sh


# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

