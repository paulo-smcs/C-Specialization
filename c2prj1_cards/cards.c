#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value>=2 && c.value<=VALUE_ACE);
  assert(c.suit>=SPADES && c.suit<=CLUBS);

}

const char * ranking_to_string(hand_ranking_t r) {

  switch(r){

  case STRAIGHT_FLUSH : return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND : return "FOUR_OF_A_KIND";
  case FULL_HOUSE : return "FULL_HOUSE";
  case  FLUSH : return " FLUSH";
  case STRAIGHT : return "STRAIGHT";
  case THREE_OF_A_KIND : return "THREE_OF_A_KIND";
  case TWO_PAIR : return "TWO_PAIR";
  case PAIR : return "PAIR";
  case NOTHING : return "NOTHING";
    
    
  }

  return "";
}

char value_letter(card_t c) {

  switch(c.value){

  case 2             :return 50;
  case 3	     :return 51;
  case 4	     :return 52;
  case 5	     :return 53;
  case 6	     :return 54;
  case 7	     :return 55;
  case 8	     :return 56;
  case 9	     :return 57;
  case 10	     :return 48;
  case VALUE_JACK    :return 74;
  case VALUE_QUEEN   :return 81;
  case VALUE_KING    :return 75;
  case VALUE_ACE     :return 65;
     
  }

  return 'x';
}


char suit_letter(card_t c) {

  switch(c.suit) {

  case SPADES:   return 's';
  case HEARTS:	 return 'h';
  case DIAMONDS: return 'd';
  case CLUBS:    return 'c';
  case NUM_SUITS: return 'x';
    
  }
  
  return 'x';
  
}

void print_card(card_t c) {

  char value=value_letter(c);
  char suit=suit_letter(c);

  printf("%c%c",value,suit);
  
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;

  switch(value_let){
  
   case 50 :temp.value=2          ; break;
   case 51 :temp.value=3          ; break;
   case 52 :temp.value=4          ; break;
   case 53 :temp.value=5          ; break;
   case 54 :temp.value=6          ; break;
   case 55 :temp.value=7          ; break;
   case 56 :temp.value=8          ; break;
   case 57 :temp.value=9          ; break;
   case 48 :temp.value=10         ; break;
   case 74 :temp.value=VALUE_JACK ; break;
   case 81 :temp.value=VALUE_QUEEN; break;
   case 75 :temp.value=VALUE_KING ; break;
   case 65 :temp.value=VALUE_ACE  ; break;
   default: temp.value=0; break;
  }

  switch (suit_let){

 case 's':temp.suit=SPADES    ; break;
 case 'h':temp.suit=HEARTS    ;	break;
 case 'd':temp.suit=DIAMONDS  ;	break;
 case 'c':temp.suit=CLUBS     ;	break;
 default :temp.suit=0 ; break;
   
  }

  assert_card_valid(temp);
  
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  assert(c>=0);
  assert(c<52);

  int suit;
  int value;
  
  suit=c/13;
  value=c%13+2;

  temp.value=value;
  temp.suit=suit;
  
  return temp;
}
