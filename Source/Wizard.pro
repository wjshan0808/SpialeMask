## 详情帮助搜索qmake Manual下 Variables, Test Functions 关键字


#工程向导类型
TEMPLATE = subdirs


CONFIG -= c99
#CONFIG += c1x
QMAKE_CFLAGS -= -std=c99
QMAKE_CFLAGS += -std=c1x


#添加工程项
SUBDIRS += SpialeMask/SpialeMask.pro \
           SpialeMaskGUI/SpialeMaskGUI.pro \
           SpialeMaskTest/SpialeMaskTest.pro


#依工程项顺序编译
CONFIG += ordered


## 请在配置项目时修改Build目录
#

