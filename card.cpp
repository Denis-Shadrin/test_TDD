#include "card.h"

Card::Card() {}
short Card::check_level_with_type(Card *other_card)
{
    //если 0 то карта такая же
    //если 1 то карта выше
    //если -1 то карта слабее
    //если -2 то карта не той масти

    if(other_card->number==number&&
        other_card->type==type
        && super == other_card->super)
        return 0;
    else if(
        (super && !other_card->super)
        ||
        (other_card->number < number &&
         other_card->type==type)
        ){
        return 1;

    }
    else if(other_card->type!=type) return -2;
    else return -1;
}

Card::Card(int number,short int type) {
    this->number=number;
    this->type=type;

}
void Card::set_super()
{
    super = true;
}
