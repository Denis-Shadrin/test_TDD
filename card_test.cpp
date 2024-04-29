#include "card_test.h"
#include "card.h"
#include <QTest>
Card_test::Card_test(QObject *parent) :
    QObject(parent) {}
void Card_test::test_compare_cards_with_type()
{
    Card a(1,1);
    Card a2(1,1);
    Card a3(2,1);
    Card b(2,2);
    Card c(1,2);

    QCOMPARE(a.check_level_with_type(&a2), 0);
    a2.set_super();
    QCOMPARE(a.check_level_with_type(&a2), -1);
    QCOMPARE(a2.check_level_with_type(&a), 1);

    QCOMPARE(a.check_level_with_type(&b), -2);
    QCOMPARE(b.check_level_with_type(&a), -2);

    QCOMPARE(a.check_level_with_type(&c), -2);

    QCOMPARE(a.check_level_with_type(&a3), -1);
    QCOMPARE(a3.check_level_with_type(&a), 1);
}
