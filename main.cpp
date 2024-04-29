#include <QCoreApplication>
#include <QTest>
#include "card_test.h"
#include "player_test.h"
int main(int argc, char *argv[])
{
    QTest::qExec(new Card_test, argc, argv);
    QTest::qExec(new Player_test, argc, argv);
    QCoreApplication a(argc, argv);

    return a.exec();
}
