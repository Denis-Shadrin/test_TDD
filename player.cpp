#include "player.h"

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
    return cards[0];
}

Card Player::ChooseLowestCard(std::vector<Card> cards_list)
{
    return cards_list[0];
}
