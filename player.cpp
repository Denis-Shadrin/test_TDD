#include "player.h"
#include <algorithm>
bool comp (Card a, Card b) {
    return b.check_level_with_type(&a) == 1 && (b.super && !a.super);
}

Player::Player() {}
void Player::SetCard(Card c)
{
    cards.push_back(c);
}

int Player::GetCardsCount()
{
    return cards.size();
}

void Player::SetCards(std::vector<Card> new_cards)
{
    int size = new_cards.size();
    for (int i = 0; i < size; ++i) {
        this->cards.push_back(new_cards[i]);
    }
}

Card Player::ChooseLowestCard()
{
    int index =0;
    Card card = cards[0];
    int size = cards.size();
    for (int i = 0; i < size; ++i) {
        if(card.check_level_without_type(&cards[i]) == 1){
            card = cards[i];
            index=i;
        }
    }
    //удаление карты из руки
    cards.erase(cards.begin()+index);
    return card;
}

Card Player::ChooseLowestCard(std::vector<Card> cards_list)
{
    Card card = cards_list[0];
    int size = cards_list.size();
    for (int i = 0; i < size; ++i) {
        if( card.check_level_without_type(&cards_list[i]) == 1){
            card = cards_list[i];
        }
    }
    return card;
}


bool Player::CanBeatTheCard(Card card)
{
    int size = cards.size();
    for (int i = 0; i < size; ++i) {
        if(cards[i].check_level_with_type(&card)==1){
            return true;
        }
    }
    return false;
}


//формирует список карт которыми можно отбится
std::vector<Card> Player::CardForBeat(Card card)
{
    std::vector<Card> card_list;
    int size = cards.size();
    for (int i = 0; i < size; ++i) {
        if(cards[i].check_level_with_type(&card)==1){
            card_list.push_back(cards[i]);
        }
    }
    //сортировка списка карт для отбоя
    sort(card_list.begin() , card_list.end(), comp);
    return card_list;
}
