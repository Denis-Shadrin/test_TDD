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

void Card_test::test_compare_cards_without_type()
{
    Card a(1,1);
    Card a2(1,1);
    Card a3(1,1);
    a3.set_super();
    Card b(2,2);
    Card c(2,1);

    QCOMPARE(a.check_level_without_type(&a2), 0);
    QCOMPARE(a.check_level_without_type(&b), -1);
    QCOMPARE(b.check_level_without_type(&a), 1);
    QCOMPARE(b.check_level_without_type(&c), 0);

    QCOMPARE(a.check_level_without_type(&c), -1);

    QCOMPARE(a.check_level_without_type(&a3), -1);
    QCOMPARE(a3.check_level_without_type(&a), 1);
}

void Card_test::test_compare_cards_without_type_super()
{
    Card a(1,1);
    a.set_super();
    Card b(10,3);

    QCOMPARE(a.check_level_without_type(&b), 1);
}

void Card_test::test_compare_cards_with_type_super()
{
    Card a(1,1);
    a.set_super();
    Card b(10,3);

    QCOMPARE(a.check_level_with_type(&b), 1);
}
