QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gamewindow.cpp \
    itemwidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    gamewindow.h \
    itemwidget.h \
    mainwindow.h

FORMS += \
    gamewindow.ui \
    itemwidget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Выбираем директорию сборки исполняемого файла
# в зависимости от режима сборки проекта
CONFIG(debug, debug|release) {
    DESTDIR = $$OUT_PWD/debug
} else {
    DESTDIR = $$OUT_PWD/release
}

COMMON_DIR = $$OUT_PWD/common
# разделяем по директориям все выходные файлы проекта
MOC_DIR = $$COMMON_DIR/moc
RCC_DIR = $$COMMON_DIR/rcc
UI_DIR = $$COMMON_DIR/ui

unix:OBJECTS_DIR = $$COMMON_DIR/o/unix
win32:OBJECTS_DIR = $$COMMON_DIR/o/win32
macx:OBJECTS_DIR = $$COMMON_DIR/o/mac

# Добавляем модуль file_copies
CONFIG += file_copies

# Добавляем переменную, описывающую копируемые файлы
COPIES +=   \
            debug_protector \

PROTECTOR_DIR = $$OUT_PWD/../DebugProtector

# в зависимости от режима сборки проекта
# запускаем win deploy приложения в целевой директории, то есть собираем все dll
CONFIG(debug, debug|release) {
    PROTECTOR_DIR = $$PROTECTOR_DIR/debug
} else {
    PROTECTOR_DIR = $$PROTECTOR_DIR/release

    QMAKE_POST_LINK += $$(QTDIR)/bin/windeployqt $$DESTDIR
}

# Определяем, с каким расширением нам необохдимо скопировать файлы и по какому пути они расположены
debug_protector.files = $$files($$PROTECTOR_DIR/*.exe)

# Указываем путь, куда копировать файлы
debug_protector.path = $$DESTDIR

