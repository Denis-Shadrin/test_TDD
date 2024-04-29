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

void Player_test::player_test_set_cards()
{
    Card a(1,1);
    std::vector<Card> cards;
    cards.push_back(a);
    cards.push_back(a);
    cards.push_back(a);
    cards.push_back(a);
    cards.push_back(a);
    cards.push_back(a);
    Player p1;
    p1.SetCards(cards);
    QCOMPARE(p1.GetCardsCount(), 6);

}

void Player_test::player_test_Choose_Lowest_Card_From_Hand()
{
    Player p1;
    Card a(10,2);
    p1.SetCard(a);


    QCOMPARE(p1.ChooseLowestCard(), a);
}

void Player_test::player_test_Choose_Lowest_Card_From_List()
{
    Player p1;
    Card a(10,2);

    std::vector<Card> v;
    v.push_back(a);

    QCOMPARE( p1.ChooseLowestCard(v), a);
}
