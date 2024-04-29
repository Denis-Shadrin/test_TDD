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
    Card a(1,1);
    cards.push_back(a);
    cards.push_back(a);
    cards.push_back(a);
    cards.push_back(a);
    cards.push_back(a);
    cards.push_back(a);
}
