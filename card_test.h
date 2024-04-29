#ifndef CARD_TEST_H
#define CARD_TEST_H

#include <QObject>

class Card_test: public QObject
{
    Q_OBJECT
public:
   explicit Card_test(QObject *parent = 0);
private slots:
    void test_compare_cards_with_type();
    void test_compare_cards_without_type();

    void test_compare_cards_without_type_super();
    void test_compare_cards_with_type_super();
};

#endif // CARD_TEST_H
