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
};

#endif // PLAYER_TEST_H
