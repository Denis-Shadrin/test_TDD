QT = core
QT += testlib gui printsupport
CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        card.cpp \
        card_test.cpp \
        game.cpp \
        main.cpp \
        player.cpp \
        player_test.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    card.h \
    card_test.h \
    game.h \
    player.h \
    player_test.h
