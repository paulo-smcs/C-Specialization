#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str) {
  //WRITE ME!

  if (*str=='\0') {return;}
  
  size_t len=strlen(str);
  char fc;
  char lc;
  
  if (len==0) {return;}

  else  {
    
    
    for (int i=0;i<(len/2);i++) {
      
      fc=str[i];
      lc = str[len-1-i];

      str[i]=lc;
      str[len-1-i]=fc;
      
    }

  }
  
  
}

int main(void) {
  
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  
  char * array[] = {str0, str1, str2};
  for (int i = 0; i <3; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
