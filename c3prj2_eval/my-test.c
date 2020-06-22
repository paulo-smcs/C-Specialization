#include <stdio.h>
#include <stdlib.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"

suit_t flush_suit(deck_t * hand);
int card_ptr_comp(const void * vp1, const void * vp2);
unsigned * get_match_counts(deck_t * hand);
int is_straight_at(deck_t * hand, size_t index, suit_t fs);
hand_eval_t build_hand_from_match(deck_t * hand,
				  unsigned n,
				  hand_ranking_t what,
				  size_t idx);
hand_eval_t evaluate_hand(deck_t * hand);

int main(void) {

  //Test the assingment function made by Paulo Sergio

    //Final function

    deck_t hand1;
    deck_t hand2;
      
  card_t h1c1,h1c2,h1c3,h1c4,h1c5,h1c6,h1c7;
  card_t h2c1,h2c2,h2c3,h2c4,h2c5,h2c6,h2c7;

  h1c1=card_from_letters('0','s');  h2c1=card_from_letters('2','h');
  h1c2=card_from_letters('9','s');  h2c2=card_from_letters('0','h');
  h1c3=card_from_letters('3','s');  h2c3=card_from_letters('4','s');
  h1c4=card_from_letters('8','s');  h2c4=card_from_letters('6','h');
  h1c5=card_from_letters('6','s');  h2c5=card_from_letters('3','c');
  h1c6=card_from_letters('4','c');  h2c6=card_from_letters('3','d');
  h1c7=card_from_letters('2','d');  h2c7=card_from_letters('9','s');
    

   card_t *hand1cards[]={&h1c1,&h1c2,&h1c3,&h1c4,&h1c5,&h1c6,&h1c7};
   card_t *hand2cards[]={&h2c1,&h2c2,&h2c3,&h2c4,&h2c5,&h2c6,&h2c7};

   hand1.cards=hand1cards; hand1.n_cards=7;
   hand2.cards=hand2cards; hand2.n_cards=7;

   printf("hand1 :");
   print_hand(&hand1);
   printf("\n");
   printf("hand2 :");
   print_hand(&hand2);
   printf("\n");
   
   //int i = compare_hands(&hand1,&hand2);
   //printf("Compare hands is: %i \n",i);

   //Evaluate hand

   printf("Sorting: \n");

   qsort(hand1.cards,hand1.n_cards,sizeof(hand1.cards[0]),card_ptr_comp);
   qsort(hand2.cards,hand2.n_cards,sizeof(hand2.cards[0]),card_ptr_comp);

   printf("hand1 :");
   print_hand(&hand1);
   printf("\n");
   printf("hand2 :");
   print_hand(&hand2);
   printf("\n");
      
   return 1;
}
