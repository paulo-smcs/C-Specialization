#include "cards.h"



int main(void) {
  
  card_t c;
  c.value=VALUE_JACK;
  c.suit=SPADES;

  hand_ranking_t hand=PAIR;
  
  
  assert_card_valid(c);
  ranking_to_string(hand);
  print_card(c);
  card_t d;
  
  d=card_from_letters('K','h');
  print_card(d);

  int num=51;
  card_t e;

  e=card_from_num(num);
  print_card(e);
  
  return 0;
}
