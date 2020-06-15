#include <stdio.h>
#include <stdlib.h>
#include "maxSeq.h"

int main(void) {

  int array1[]={ 1, 2, 3};
  
  if (maxSeq(array1,3)!=3) {

    printf("Failure 1, the value calculated was: %lu\n",maxSeq(array1,3)) ;
    return EXIT_FAILURE;}

  int array2[]={-3,-2,-1,0};
  
  if(maxSeq(array2,4) !=4)  {

    printf("Failure 2, the value calculated was: %lu\n",maxSeq(array2,4));
    return EXIT_FAILURE;
  }

  int array3[]={-5,0,-7,0};

  if(maxSeq(array3,4) !=2)  {printf("Failure 3\n");return EXIT_FAILURE;}

  int array4[]={0,1,5};

  if(maxSeq(array4,3) !=3)  {printf("Failure 4\n");return EXIT_FAILURE;}

  int array5[]={-1,-1,-1};

  if(maxSeq(array5,3) != 1) {printf("Failure 5\n"); return EXIT_FAILURE;}

  int array6[]={3,3,3,4};

  if(maxSeq(array6,4) !=2)  {printf("Failure 6\n");return EXIT_FAILURE;}
  
  else {

    printf("Ok \n");

    return EXIT_SUCCESS;
  }
}
