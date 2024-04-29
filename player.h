#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"

class Player
{
public:
    Player();
    void SetCard(Card c);//получает карту в руку
    int GetCardsCount();//возвращает количество карт в руке
};

#endif // PLAYER_H
