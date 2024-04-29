#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <vector>
class Player
{
    std::vector<Card> cards;
public:
    Player();
    void SetCard(Card c);//получает карту в руку
    int GetCardsCount();//возвращает количество карт в руке
    void SetCards(std::vector<Card> new_cards);//получает карты в руку

};

#endif // PLAYER_H
