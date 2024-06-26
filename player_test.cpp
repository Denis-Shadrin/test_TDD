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
    Card b(7,1);
    Card c(3,4);
    Card d(10,3);
    p1.SetCard(a);
    p1.SetCard(b);
    p1.SetCard(c);
    p1.SetCard(d);

    QCOMPARE(p1.ChooseLowestCard(), c);
}

void Player_test::player_test_Choose_Lowest_Card_From_List()
{
    Player p1;
    Card a(10,2);
    Card b(7,1);
    Card c(3,4);
    Card d(10,3);
    std::vector<Card> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);

    QCOMPARE( p1.ChooseLowestCard(v), c);
}

void Player_test::player_test_Can_Beat_the_card()
{
    Player p1;
    Card a(10,2);
    Card b(7,1);
    Card c(3,4);
    Card d(10,3);

    p1.SetCard(a);
    p1.SetCard(b);
    p1.SetCard(c);
    p1.SetCard(d);

    Card t1(9,2);
    Card t2(13,3);

    QCOMPARE(p1.CanBeatTheCard(t1), true);
    QCOMPARE(p1.CanBeatTheCard(t2), false);
}

void Player_test::player_test_Can_Beat_the_super_card()
{
    Player p1;

    Card s(8,2);
    s.set_super();

    Card t(13,3);

    p1.SetCard(s);
    QCOMPARE(p1.CanBeatTheCard(t), true);
}


void Player_test::player_test_CardForBeat()
{
    Player p1;
    Card a(1,1);
    Card b(1,2);
    Card c(6,2);
    Card d(11,2);

    Card t(5,2);

    p1.SetCard(a);
    p1.SetCard(b);
    p1.SetCard(c);
    p1.SetCard(d);

    std::vector<Card> v = p1.CardForBeat(t);
    QCOMPARE(v[0], c);
    QCOMPARE(v[1], d);
    return;
}

void Player_test::player_test_CardForBeat_with_super_card()
{
    Player p1;
    Card a(1,1);
    Card b(1,2);
    Card c(1,3);
    c.set_super();

    Card t(1,4);

    p1.SetCard(a);
    p1.SetCard(b);
    p1.SetCard(c);


    std::vector<Card> v = p1.CardForBeat(t);

    QCOMPARE(v[0], c);

    return;
}

void Player_test::player_test_CanAddCardToTable()
{
    Player p1;
    Card a(1,2);
    Card b(7,1);
    Card c(3,4);
    Card d(10,3);
    p1.SetCard(a);
    p1.SetCard(b);
    p1.SetCard(c);
    p1.SetCard(d);

    Card d1(7,2);
    Card d2(10,4);

    std::vector<Card> cards_on_table;

    cards_on_table.push_back(d1);
    cards_on_table.push_back(d2);


    QCOMPARE( p1.CanAddCardToTable(cards_on_table), true);

}

void Player_test::player_test_AddCardToTable()
{
    Player p1;
    Card a(10,2);
    Card b(7,1);
    Card c(3,4);
    Card d(10,3);
    p1.SetCard(a);
    p1.SetCard(b);
    p1.SetCard(c);
    p1.SetCard(d);

    Card d1(7,2);
    Card d2(10,4);

    std::vector<Card> cards_on_table;

    cards_on_table.push_back(d1);
    cards_on_table.push_back(d2);

    p1.CanAddCardToTable(cards_on_table);
    Card t1 =p1.ChooseLowestCardForAddToTable();
    QCOMPARE( t1.number, d1.number);
}

