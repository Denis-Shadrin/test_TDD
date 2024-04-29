#include "card_test.h"
#include "card.h"
#include <QTest>
Card_test::Card_test(QObject *parent) :
    QObject(parent) {}
void Card_test::test_card()
{
    Card a;

    QCOMPARE(a.check_level_with_type(), 1);


}
