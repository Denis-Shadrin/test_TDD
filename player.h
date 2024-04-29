#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <vector>
class Player
{
    std::vector<Card> cards;
    std::vector<Card> CardsCanBeAddedToTable;//карты которые можно подкинуть на стол
    void RemoveCardFromHand(Card card);
public:
    Player();
    void SetCard(Card c);//получает карту в руку
    int GetCardsCount();//возвращает количество карт в руке
    void SetCards(std::vector<Card> new_cards);//получает карты в руку


    Card ChooseLowestCard();//самая слабая карта из руки
    Card ChooseLowestCard(std::vector<Card> cards_list);//самая слабая карта из списка

    bool CanBeatTheCard(Card card);//может ли побить карту
    std::vector<Card> CardForBeat(Card card);


    bool CanAddCardToTable(std::vector<Card> cardOnTable);

    Card ChooseLowestCardForAddToTable();
};

#endif // PLAYER_H
