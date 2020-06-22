#include "eval.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int card_ptr_comp(const void * vp1, const void * vp2) {

  const card_t * const * c1 = vp1;
  const card_t * const * c2 = vp2;

  
  if( ((*c1)->value) > ((*c2)->value)){return -1;}
  
  if( ((*c1)->value) < ((*c2)->value)){return 1;}
  
  if( ((*c1)->suit)  > ((*c2)->suit)) {return -1;}

  if( ((*c1)->suit)  < ((*c2)->suit)) {return 1;}
  
  return 0;
}

suit_t flush_suit(deck_t * hand) {

  deck_t h = *hand;

  for(int i=0;i<4;i++) {

    int count=0;

    for(int j=0;j<h.n_cards;j++) {
      
      if((*(h.cards[j])).suit==i) {count++;}
      
      
    }

    if(count==5){return i;}
    
  }
  
  return NUM_SUITS;
}

unsigned get_largest_element(unsigned * arr, size_t n) {

  unsigned ans=arr[0];

  for(int i=0;i<n;i++)
    {
      if( arr[i]>ans){ans=arr[i];}
    }
  
  return ans;
}

size_t get_match_index(unsigned * match_counts, size_t n,unsigned n_of_akind){
  
  for(int i=0;i<n;i++){
    
    if(match_counts[i]==n_of_akind) { return i;}
  }
  
  exit(EXIT_FAILURE);
}

ssize_t  find_secondary_pair(deck_t * hand,
			     unsigned * match_counts,
			     size_t match_idx) {

  size_t n=(*hand).n_cards;
  card_t c_idx=*((*hand).cards[match_idx]);

  for (int i=match_idx;i<n;i++) {
    
    card_t c_i=*((*hand).cards[i]);
    
    if(match_counts[i]>1 && c_idx.value!=c_i.value) {return i;}     
    
  }

  
  return -1;
}

int is_straight_at(deck_t * hand, size_t index, suit_t fs) {
  
  
  size_t n=(*hand).n_cards; //Size of the hand
  card_t ** cards=(*hand).cards; //Array of pointers to the cards
  card_t c_idx=*cards[index]; //First card of our index
  suit_t suit_array[n]; //Array of suits that will help us
  int count =1; //Count for straight
  //char As;
  //int hand_A=0;//Check if there is an A in the Deck
  // int straight=0;

  //make a suit array

  for(int i=0;i<n;i++){

    *(suit_array+i)=(*(cards[i])).suit ;
   
   }
  
  //Check if hand contains A

  if(fs==4) {
  
    //if(deck_contains(hand,card_from_letters('A','s')))      {hand_A=1; }
    //else if(deck_contains(hand,card_from_letters('A','h'))) {hand_A=1; }
    //else if(deck_contains(hand,card_from_letters('A','d'))) {hand_A=1; }
    //else if(deck_contains(hand,card_from_letters('A','c'))) {hand_A=1; }
  

  for(int i=index+1;i<n;i++) {

    
    
    card_t c_i=*cards[i];
    
    if((c_idx.value-c_i.value)==1) {c_idx=c_i; count++;}
    
  }
  
  if(count>=5) {return 1;}

  //case A
  
  c_idx=*cards[index];
  
  int i5=0;
  
  if (c_idx.value==VALUE_ACE) {

    for(int i=index+1;i<n;i++) {

    card_t c_i=*cards[i];
    
    if(c_i.value==5) {i5=i;}
    
  }

    //printf("i5 is: %i \n",i5);
    
    if(i5==0){return 0;}
    
    count=1;

    c_idx=*cards[i5];
    
     for(int i=i5+1;i<n;i++) {

    card_t c_i=*cards[i];
    
    if((c_idx.value-c_i.value)==1) {c_idx=c_i; count++;}
    
  }

     //printf("Count case A: %i",count);
     if(count==4) {return -1;}
    
  }
  
  }

  

  if(fs!=4) {
  
    //if(deck_contains(hand,card_from_letters('A','s'))&& fs==0)      {hand_A=1; }
    //else if(deck_contains(hand,card_from_letters('A','h'))&& fs==1) {hand_A=1; }
    //else if(deck_contains(hand,card_from_letters('A','d'))&& fs==2) {hand_A=1; }
    //else if(deck_contains(hand,card_from_letters('A','c'))&& fs==3) {hand_A=1; }
  
  if(suit_array[index]!=fs) {return 0;}

  for(int i=index+1;i<n;i++) {

    
    card_t c_i=*cards[i];

    if((c_idx.value!=c_i.value) && suit_array[i]!=fs ) {return 0;} 
    if((c_idx.value-c_i.value)==1 && suit_array[i]==fs ) {c_idx=c_i; count++;}
    
    
  }
  
  if(count>=5) {return 1;}

  //Case A

  c_idx=*cards[index];
  
  int i5=0;
  
  if (c_idx.value==VALUE_ACE) {

    for(int i=index+1;i<n;i++) {

    card_t c_i=*cards[i];
    
    if(c_i.value==5) {i5=i;}
    
  }

    //printf("i5 is: %i \n",i5);
    
    if(i5==0){return 0;}
    
    count=1;

    c_idx=*cards[i5];
    
     for(int i=i5+1;i<n;i++) {

    card_t c_i=*cards[i];
    
    if((c_idx.value!=c_i.value) && suit_array[i]!=fs ) {return 0;} 
    if((c_idx.value-c_i.value)==1 && suit_array[i]==fs ) {c_idx=c_i; count++;}

    
  }

     //printf("Count case A: %i",count);
     if(count==4) {return -1;}
    
  }
  

  }
  
  return 0;
}
  


hand_eval_t build_hand_from_match(deck_t * hand,
				  unsigned n,
				  hand_ranking_t what,
				  size_t idx) {

  hand_eval_t ans;
  ans.ranking=what;

  if(what==NOTHING){

    for (int i=0;i<5;i++){

      ans.cards[i]=hand->cards[i];
    }

    return ans;
  }

  card_t *array_cards[5];

  for (int i=idx;i<n+idx;i++){

    array_cards[i-idx]=((hand->cards)[i]);
    
    
    
  }

  int n_index=n;
  int j=0;

  for (int i=0;i<hand->n_cards;i++){

    if(i<idx || i>(idx+n-1)){

      array_cards[n_index]=((hand->cards)[i]);
      n_index++;
      j++;
    }

    if(j >= 5-n){break;}
  }

  for(int i=0;i<5;i++){
    
    ans.cards[i]=array_cards[i];
  }
  
  
  
  return ans;

  
}


int compare_hands(deck_t * hand1, deck_t * hand2) {

  //Sorting hands


  qsort(hand1->cards,hand1->n_cards,sizeof(hand1->cards[0]),card_ptr_comp);
  qsort(hand2->cards,hand2->n_cards,sizeof(hand1->cards[0]),card_ptr_comp);
  
  hand_eval_t hand1_eval;
  hand_eval_t hand2_eval;

  hand1_eval=evaluate_hand(hand1);
  hand2_eval=evaluate_hand(hand2);
  
  if(hand1_eval.ranking>hand2_eval.ranking){ return -1;}
  if(hand2_eval.ranking>hand1_eval.ranking){ return  1;}

  for (int i=0;i<5;i++) {
    
    if( (*((hand1_eval.cards)[i])).value > (*((hand2_eval.cards)[i])).value){return 1;}
    if( (*((hand2_eval.cards)[i])).value > (*((hand1_eval.cards)[i])).value){return -1;}
    
    
  }
  
  return 0;
}



//You will write this function in Course 4.
//For now, we leave a prototype (and provide our
//implementation in eval-c4.o) so that the
//other functions we have provided can make
//use of get_match_counts.
unsigned * get_match_counts(deck_t * hand) ;

// We provide the below functions.  You do NOT need to modify them
// In fact, you should not modify them!


//This function copies a straight starting at index "ind" from deck "from".
//This copies "count" cards (typically 5).
//into the card array "to"
//if "fs" is NUM_SUITS, then suits are ignored.
//if "fs" is any other value, a straight flush (of that suit) is copied.
void copy_straight(card_t ** to, deck_t *from, size_t ind, suit_t fs, size_t count) {
  assert(fs == NUM_SUITS || from->cards[ind]->suit == fs);
  unsigned nextv = from->cards[ind]->value;
  size_t to_ind = 0;
  while (count > 0) {
    assert(ind < from->n_cards);
    assert(nextv >= 2);
    assert(to_ind <5);
    if (from->cards[ind]->value == nextv &&
	(fs == NUM_SUITS || from->cards[ind]->suit == fs)){
      to[to_ind] = from->cards[ind];
      to_ind++;
      count--;
      nextv--;
    }
    ind++;
  }
}


//This looks for a straight (or straight flush if "fs" is not NUM_SUITS)
// in "hand".  It calls the student's is_straight_at for each possible
// index to do the work of detecting the straight.
// If one is found, copy_straight is used to copy the cards into
// "ans".
int find_straight(deck_t * hand, suit_t fs, hand_eval_t * ans) {
  if (hand->n_cards < 5){
    return 0;
  }
  for(size_t i = 0; i <= hand->n_cards -5; i++) {
    int x = is_straight_at(hand, i, fs);
    if (x != 0){
      if (x < 0) { //ace low straight
	assert(hand->cards[i]->value == VALUE_ACE &&
	       (fs == NUM_SUITS || hand->cards[i]->suit == fs));
	ans->cards[4] = hand->cards[i];
	size_t cpind = i+1;
	while(hand->cards[cpind]->value != 5 ||
	      !(fs==NUM_SUITS || hand->cards[cpind]->suit ==fs)){
	  cpind++;
	  assert(cpind < hand->n_cards);
	}
	copy_straight(ans->cards, hand, cpind, fs,4) ;
      }
      else {
	copy_straight(ans->cards, hand, i, fs,5);
      }
      return 1;
    }
  }
  return 0;
}


//This function puts all the hand evaluation logic together.
//This function is longer than we generally like to make functions,
//and is thus not so great for readability :(
hand_eval_t evaluate_hand(deck_t * hand) {
  suit_t fs = flush_suit(hand);
  hand_eval_t ans;
  if (fs != NUM_SUITS) {
    if(find_straight(hand, fs, &ans)) {
      ans.ranking = STRAIGHT_FLUSH;
      return ans;
    }
  }
  unsigned * match_counts = get_match_counts(hand);
  unsigned n_of_a_kind = get_largest_element(match_counts, hand->n_cards);
  assert(n_of_a_kind <= 4);
  size_t match_idx = get_match_index(match_counts, hand->n_cards, n_of_a_kind);
  ssize_t other_pair_idx = find_secondary_pair(hand, match_counts, match_idx);
  free(match_counts);
  if (n_of_a_kind == 4) { //4 of a kind
    return build_hand_from_match(hand, 4, FOUR_OF_A_KIND, match_idx);
  }
  else if (n_of_a_kind == 3 && other_pair_idx >= 0) {     //full house
    ans = build_hand_from_match(hand, 3, FULL_HOUSE, match_idx);
    ans.cards[3] = hand->cards[other_pair_idx];
    ans.cards[4] = hand->cards[other_pair_idx+1];
    return ans;
  }
  else if(fs != NUM_SUITS) { //flush
    ans.ranking = FLUSH;
    size_t copy_idx = 0;
    for(size_t i = 0; i < hand->n_cards;i++) {
      if (hand->cards[i]->suit == fs){
	ans.cards[copy_idx] = hand->cards[i];
	copy_idx++;
	if (copy_idx >=5){
	  break;
	}
      }
    }
    return ans;
  }
  else if(find_straight(hand,NUM_SUITS, &ans)) {     //straight
    ans.ranking = STRAIGHT;
    return ans;
  }
  else if (n_of_a_kind == 3) { //3 of a kind
    return build_hand_from_match(hand, 3, THREE_OF_A_KIND, match_idx);
  }
  else if (other_pair_idx >=0) {     //two pair
    assert(n_of_a_kind ==2);
    ans = build_hand_from_match(hand, 2, TWO_PAIR, match_idx);
    ans.cards[2] = hand->cards[other_pair_idx];
    ans.cards[3] = hand->cards[other_pair_idx + 1];
    if (match_idx > 0) {
      ans.cards[4] = hand->cards[0];
    }
    else if (other_pair_idx > 2) {  //if match_idx is 0, first pair is in 01
      //if other_pair_idx > 2, then, e.g. A A K Q Q
      ans.cards[4] = hand->cards[2];
    }
    else {       //e.g., A A K K Q
      ans.cards[4] = hand->cards[4];
    }
    return ans;
  }
  else if (n_of_a_kind == 2) {
    return build_hand_from_match(hand, 2, PAIR, match_idx);
  }
  return build_hand_from_match(hand, 0, NOTHING, 0);
}
