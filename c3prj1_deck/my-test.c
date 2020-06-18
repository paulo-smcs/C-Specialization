#include <stdio.h>
#include "cards.h"
#include "deck.h"

int main(void) {

  card_t c;

  //Testing print card
  
  c.value=VALUE_JACK;
  c.suit=DIAMONDS;
  
  print_card(c);
  printf("\n\n");

  card_t c2;

  //Testing print from letters

  
  char value_let[]={'2','3','4','5','6','7','8','9','0','J','Q','K','A'};
  char suit_let[]={'d','c','s','h'};
  
  printf("---Printing all characters --- \n");
  
  for(int i=0;i<13;i++) {

    for(int j=0;j<4;j++) {

      c2=card_from_letters(value_let[i],suit_let[j]);
      print_card(c2);
      printf(" ");
      
    }
    
    printf("\n");
  }

  //Testing deck h functions

  printf("\nTesting hand \n");
  
  deck_t hand;
  
  
  card_t c3 , c4,c5; 

    c3=card_from_letters('3','h');
    c4=card_from_letters('J','d');
    c5=card_from_letters('K','s');

      card_t *hand_h[]={&c3,&c4};

    hand.cards=hand_h;
    hand.n_cards=2;

    deck_t * ptr_hand=&hand;

    printf("Our hand\n");
    print_hand(ptr_hand);
    printf("\n");

    printf("Deck contains 3h? %i \n",deck_contains(ptr_hand,c3));
    printf("Deck contains Ks? %i \n",deck_contains(ptr_hand,c5));
    
  return 1;
}
