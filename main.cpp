#include <QCoreApplication>
#include <QTest>
#include "card_test.h"
int main(int argc, char *argv[])
{
    QTest::qExec(new Card_test, argc, argv);
    QCoreApplication a(argc, argv);

    return a.exec();
}
