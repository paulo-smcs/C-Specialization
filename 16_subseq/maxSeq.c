#include <stdio.h>
#include <stdlib.h>
#include "maxSeq.h"


size_t maxSeq(int * array, size_t n){

  int ans=1;
  int count=1;

  if(n==0){return 0;}
  
  for (int j=1;j<n;j++) {

    for (int i=j;i<n;i++){

      if(array[i]>array[i-1]) {

	count++;
	
      }

      else {
	break;
      }

      

    }

    if(count>ans) {ans=count;}
    count=1;
  }

  return ans;
  
}


