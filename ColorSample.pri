SRC_PATH = $$PWD/Sources

INCLUDEPATH += $${SRC_PATH}

SOURCES += $${SRC_PATH}/QCustomToggleButton.cpp \
    $${SRC_PATH}/QSandBoxDialog.cpp \
    $${SRC_PATH}/main.cpp

HEADERS  += $${SRC_PATH}/QCustomToggleButton.h \
    $${SRC_PATH}/QSandBoxDialog.h

RESOURCES += \
    $${SRC_PATH}/Resources/resources.qrc
