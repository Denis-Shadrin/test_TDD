#include "player_test.h"
#include "player.h"
#include <QTest>
Player_test::Player_test(QObject *parent) :
    QObject(parent) {}
void Player_test::player_test_count_cards()
{
    Card a(1,1);
    Player p1;

    p1.SetCard(a);
    p1.SetCard(a);
    p1.SetCard(a);
    p1.SetCard(a);

    QCOMPARE(p1.GetCardsCount(), 4);
}
