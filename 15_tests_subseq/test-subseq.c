#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main(void) {

  int array1[]={};
  
  if (maxSeq(array1,0)!=0) {return EXIT_FAILURE;}

  int array2[]={-3,-2,-1,0};
  
  if(maxSeq(array2,4) !=4)  {return EXIT_FAILURE;}

  int array3[]={-5,0,-7,0};

  if(maxSeq(array3,4) !=2)  {return EXIT_FAILURE;}

  int array4[]={0,1,5};

  if(maxSeq(array4,3) !=3)  {return EXIT_FAILURE;}

  int array5[]={-1,-1,-1};

  if(maxSeq(array5,3) != 1) { return EXIT_FAILURE;}

  int array6[]={3,3,3,4};

  if(maxSeq(array6,4) !=2)  {return EXIT_FAILURE;}
  
  else {

    return EXIT_SUCCESS;
  }
}
