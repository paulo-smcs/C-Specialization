#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){

  
  for(int i=0;i<(*hand).n_cards;i++){
    
    print_card(*(((*hand).cards)[i]));
     printf(" ");
 
  } 
}

int deck_contains(deck_t * d, card_t c) {
  
   for(int i=0;i<(*d).n_cards;i++){
    
     if((*(((*d).cards)[i])).value==c.value && (*(((*d).cards)[i])).suit==c.suit){
       return 1;}
   
   }
  
  
  return 0;
}

void shuffle(deck_t * d){

  size_t N_MAX=(*d).n_cards;

  int i=0;
  
  while (i<10) {

    card_t * s1;
    card_t * s2;

    //Dirty shuffling, this might not be a uniform distro
    
    int j=random() % N_MAX;
    int w=random() % N_MAX;
    
    s1=(*d).cards[j];
    s2=(*d).cards[w];

    (*d).cards[j]=s2;
    (*d).cards[w]=s1;

    int x=random() % N_MAX;
    int z=random() % N_MAX;

    
    s1=(*d).cards[x];
    s2=(*d).cards[z];

    (*d).cards[x]=s2;
    (*d).cards[z]=s1;

    i++;
  }

}

void assert_full_deck(deck_t * d) {

 
  
  for(int i=0;i<52;i++){

     assert(deck_contains(d,card_from_num(i)));
  }

}
