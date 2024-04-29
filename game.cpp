#include "game.h"
#include <iostream>
#include <algorithm>

Game::Game() {
    CreateDeck();
    RandomizeDeck();

    //Test_deck();

    SetSuperCard();

    std::cout <<super_card_number<<std::endl;
    PrintDeck();
    players_count = 2;
    players.push_back(Player());
    players.push_back(Player());
}

void Game::StartGame()
{
    DealCards();

    leading_player_number =0;
    receiving_player_number = 1;


    bool game_end=false;

    while (!game_end) {
        //1 отбился
        //2 не отбился и берёт карты со стола
        short int turn_status=0;

        //ход
        while(!turn_status){
            Card card1;
            if(players[leading_player_number].CanAddCardToTable(cards_on_the_table)){
                card1= players[leading_player_number].ChooseLowestCardForAddToTable();
                cards_on_the_table.push_back(card1);//карта кладётся на стол
                std::cout << "Игрок "<< leading_player_number+1<<
                    " Выкладывает карту "<< card1.number <<
                    " Тип карты = " <<card1.type<<
                    " Козырная? "<< card1.super
                          <<std::endl;
                //если у игрока который ходит не осталось карт
                //и карт не осталось в колоде то он выиграл
                if(players[leading_player_number].GetCardsCount()==0 &&
                    cards_in_the_deck.size()==0){
                    game_end= true;
                    break;
                }
            }
            else{
                std::cout <<"Игрок "<<leading_player_number+1 << " не может добавить карт" <<std::endl;
                turn_status=1;
            }


            if(turn_status!=1){//если есть карта на столе то второй игрок должен отбивать
                //проверка может ли игрок отбить карту
                if(players[receiving_player_number].CanBeatTheCard(card1) ){
                    std::cout << "Игрок "<< receiving_player_number+1<< " может отбить карту"<<std::endl;
                    //если может выбирает и кладёт на стол
                    Card card2 = players[receiving_player_number].BeatTheCard(card1);
                    std::cout << "Игрок "<< receiving_player_number+1<<
                        " отбивается картой "<< card2.number <<
                        " Тип карты = " <<card2.type<<
                        " Козырная? "<< card2.super
                              <<std::endl;
                    cards_on_the_table.push_back(card2);
                    //если у игрока который отбивался не осталось карт
                    //и карт не осталось в колоде то он выиграл
                    if(players[receiving_player_number].GetCardsCount()==0 &&
                        cards_in_the_deck.size()==0){
                        std::cout << "У игрока "<< receiving_player_number<<
                            " кончились карты и в колоде нет карт"<<std::endl<<
                            "Игрок "<< receiving_player_number<< " победил"<<std::endl;
                        game_end= true;
                        break;
                    }
                }
                else{
                    std::cout<< "Игрок "<< receiving_player_number+1<<" не может отбить карту и забирает карты со стола"<<std::endl;
                    //если не может отбить карту
                    //игрок забирает карты со стола а стол очищается
                    players[receiving_player_number].SetCards(cards_on_the_table);
                    turn_status=2;
                }
            }


        }


        GetCardsToPlayer(leading_player_number);

        GetCardsToPlayer(receiving_player_number);

        //после добора карт
        if(players[leading_player_number].GetCardsCount() ==0 ||
            players[receiving_player_number].GetCardsCount() ==0){
            //игра закончена
            std::cout << "Игра закончена"<<std::endl;

            std::cout << "карт в колоде "<< cards_in_the_deck.size()<<std::endl;
            std::cout << "карт у игрока 1 "<< players[0].GetCardsCount() <<std::endl;
            std::cout << "карт у игрока 2 "<< players[1].GetCardsCount() <<std::endl;

            if(players[leading_player_number].GetCardsCount() ==0 &&
                players[receiving_player_number].GetCardsCount() ==0){
                //ничья
                std::cout << "Ничья"<<std::endl;
            }
            if(players[leading_player_number].GetCardsCount() !=0 &&
                players[receiving_player_number].GetCardsCount() ==0){
                //победил игрок receiving_player_number+1
                std::cout << "Победил игрок "<<receiving_player_number+1<<std::endl;
            }
            if(players[leading_player_number].GetCardsCount() ==0 &&
                players[receiving_player_number].GetCardsCount() !=0){
                //победил игрок leading_player_number+1
                std::cout << "Победил игрок "<<leading_player_number+1<<std::endl;
            }
            game_end = true;
            //break;
        }
        if(!game_end){//если игра не закончина то возможно меняем игроков местами
            if(turn_status==1){//если игрок отбился
                std::cout<< "Игрок "<< receiving_player_number+1<<" отбился"<<std::endl;

                //меняется игрок который ходит
                int temp = leading_player_number;
                leading_player_number = receiving_player_number;
                receiving_player_number=temp;
            }
            else if(turn_status==2){//если игрок взял карты
                std::cout<< "Игрок "<< receiving_player_number+1<<" не отбился"<<std::endl;
                //не меняется игрок который ходит
            }
        }
        cards_on_the_table.clear();

    }
    std::cout << "Игра закончена " <<std::endl;
    //игра закончена
    return;
}

void Game::CreateDeck()
{
    cards_in_the_deck.clear();


    for (int i = 1; i < 5; ++i) {
        for (int j = 0; j < 9; ++j) {
            Card new_card(j+6,i);
            cards_in_the_deck.push_back(new_card);
        }
    }
    std::cout<< "Колода создана"<<std::endl;
}

void Game::RandomizeDeck()
{
    std::random_shuffle(cards_in_the_deck.begin(),cards_in_the_deck.end());
    std::cout<< "Колода перетасована"<<std::endl;
}

void Game::Test_deck()
{
    cards_in_the_deck.clear();

    cards_in_the_deck.push_back(Card(13,3));
    cards_in_the_deck.push_back(Card(12,4));
    cards_in_the_deck.push_back(Card(8 ,4));
    cards_in_the_deck.push_back(Card(10,1));
    cards_in_the_deck.push_back(Card(13,2));
    cards_in_the_deck.push_back(Card(6 ,1));
    cards_in_the_deck.push_back(Card(11,2));
    cards_in_the_deck.push_back(Card(6 ,4));
    cards_in_the_deck.push_back(Card(11,4));
    cards_in_the_deck.push_back(Card(12,1));
    cards_in_the_deck.push_back(Card(10,3));
    cards_in_the_deck.push_back(Card(7 ,2));
    cards_in_the_deck.push_back(Card(11,1));
    cards_in_the_deck.push_back(Card(7 ,1));
    cards_in_the_deck.push_back(Card(14,3));
    cards_in_the_deck.push_back(Card(9 ,4));
    cards_in_the_deck.push_back(Card(9 ,1));
    cards_in_the_deck.push_back(Card(13,1));
    cards_in_the_deck.push_back(Card(14,4));
    cards_in_the_deck.push_back(Card(8 ,3));
    cards_in_the_deck.push_back(Card(13,4));
    cards_in_the_deck.push_back(Card(12,3));
    cards_in_the_deck.push_back(Card(8 ,2));
    cards_in_the_deck.push_back(Card(10,2));
    cards_in_the_deck.push_back(Card(10,4));
    cards_in_the_deck.push_back(Card(14,1));
    cards_in_the_deck.push_back(Card(8 ,1));
    cards_in_the_deck.push_back(Card(6 ,2));
    cards_in_the_deck.push_back(Card(14,2));
    cards_in_the_deck.push_back(Card(6 ,3));
    cards_in_the_deck.push_back(Card(9 ,3));
    cards_in_the_deck.push_back(Card(7 ,3));
    cards_in_the_deck.push_back(Card(9 ,2));
    cards_in_the_deck.push_back(Card(12,2));
    cards_in_the_deck.push_back(Card(7 ,4));
    cards_in_the_deck.push_back(Card(11,3));
}

void Game::SetSuperCard()
{
    super_card_number = cards_in_the_deck[cards_in_the_deck.size()-1].type;
    int size =cards_in_the_deck.size();
    for (int i = 0; i < size; ++i) {
        if (cards_in_the_deck[i].type == super_card_number){
            cards_in_the_deck[i].set_super();
        }
    }
    std::cout<< "Козырная карта установлена"<<std::endl;
}

void Game::DealCards()
{
    for (int i = 0; i < players_count; ++i) {
        for (int j = 0; j < 6; ++j) {
            Card c = cards_in_the_deck[0];
            players[i].SetCard(c);
            cards_in_the_deck.erase(cards_in_the_deck.begin());
        }
    }

    std::cout<< "Карты выданы игрокам"<<std::endl;
    int size = players.size();
    for (int i = 0; i < size; ++i) {
        int size2 = players[i].GetCardsCount();
        std::vector<Card> player_cards = players[i].GetPlayerCards();
        std::cout<< "Карты игрока "<< i+1 <<std::endl;
        for (int j = 0; j < size2; ++j) {
            std::cout <<"Номер карты "<<player_cards[j].number<<
                " Тип карты = " <<player_cards[j].type<<
                " Козырная? "<< player_cards[j].super <<std::endl;
        }
    }

}

void Game::GetCardsToPlayer(int player_number)
{
    int counter=0;
    while (players[player_number].GetCardsCount() <6 && cards_in_the_deck.size()) {
        players[player_number].SetCard(cards_in_the_deck[0]);
        cards_in_the_deck.erase(cards_in_the_deck.begin());
        counter++;
    }
    std::cout << "Игрок "<< player_number+1 <<" добрал "<<counter << " карт"<<std::endl;

}

bool Game::Endgame()
{
    int size = players.size();
    short int count_players_with_card=0;
    for (int i = 0; i < size; ++i) {
        if(players[i].GetCardsCount()) count_players_with_card++;
    }
    if (count_players_with_card == 1 || count_players_with_card == 0) return true;
    return false;
}



void Game::PrintDeck()
{
    int size = cards_in_the_deck.size();
    for (int i = 0; i < size; ++i) {
        std::cout <<"num = "<< cards_in_the_deck[i].number <<
            " type = "<< cards_in_the_deck[i].type <<
            " super? "<<cards_in_the_deck[i].super
                  << std::endl;
    }
}
