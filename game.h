#ifndef GAME_H
#define GAME_H
#include "player.h"
class Game
{
private:
    std::vector<Player> players;
    int players_count;
    short int leading_player_number;//игрок ходит
    short int receiving_player_number;//игрок отбивается
    short int super_card_number;//номер козырной карты
    std::vector<Card> cards_in_the_deck;//карты в колоде
    std::vector<Card> cards_on_the_table;//карты на столе


    void CreateDeck();//создать колоду
    void RandomizeDeck();//перемешать колоду
    void Test_deck();

    void SetSuperCard();//установить козырь
    void DealCards();//раздать карты
    void GetCardsToPlayer(int player_number);//добавить карты игроку
    bool Endgame();//если всего у одного игрока остались карты
public:
    Game();

    void StartGame();

    void PrintDeck();
};

#endif // GAME_H
