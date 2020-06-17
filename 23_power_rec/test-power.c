#include <stdlib.h>
#include <stdio.h>

unsigned power(unsigned x,unsigned y);

void runCheck (unsigned x, unsigned y,unsigned expected_answer) {

  if (power(x,y)!=expected_answer) {

    printf("Failed case %u and %u \n",x,y);
    exit(EXIT_FAILURE);}
  
}

int main(void) {

  runCheck(1,1,1);
  runCheck(0,0,1);
  runCheck(1,4,1);
  runCheck(3,0,1);
  runCheck(2,3,8);
  runCheck(2,4,16);
  runCheck(-1,2,1);
  runCheck(-1,0,1);
  runCheck(-2,3,-8);
  
  printf("Passed all test's \n");


  return EXIT_SUCCESS;

}
