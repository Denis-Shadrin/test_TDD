#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

#include <QObject>

class Player_test:public QObject
{
    Q_OBJECT
public:
    explicit Player_test(QObject *parent = 0);

private slots:
    void player_test_count_cards();
    void player_test_set_cards();

    //тесты на выбор минимальной карты
    void player_test_Choose_Lowest_Card_From_Hand();
    void player_test_Choose_Lowest_Card_From_List();

    void player_test_Can_Beat_the_card();
    void player_test_Can_Beat_the_super_card();

    void player_test_CardForBeat();
    void player_test_CardForBeat_with_super_card();

};

#endif // PLAYER_TEST_H
