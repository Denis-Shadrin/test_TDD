#ifndef CARD_H
#define CARD_H

class Card
{
public:
    int number; //номер карты
    short int type; //масть 1)♥  2)♦ 3)♣ 4)♠
    bool super = false; //козырь

    Card();
    Card(int number,short int type);


    void set_super();
    short int check_level_with_type(Card *other_card);
    short int check_level_without_type(Card *other_card);
};

#endif // CARD_H
