#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  
  int months;
  double contribution;
  double rate_of_return;
  
};

typedef struct _retire_info retire_info;

double accountPlus(retire_info x,double account) {

  double interest=account*(x.rate_of_return/(double) 12);
  account+=interest;
  account+=x.contribution;

  return account;
}



int checkMonth(int month) {

  if (month==12) {
    return 1;
  }

  else {
    return 0;

  }
  
}

void retirement(int startAge,double initial,retire_info working,retire_info retired){

   int work_months=working.months;
   int retired_months=retired.months;
  
  int month_age=startAge%12;
  startAge=startAge/12;
  
  for(int i=1;i<=work_months;i++){

    
    printf("Age %3d month %2d you have $%.2f\n",startAge,month_age,initial);
    initial=accountPlus(working,initial);

    month_age++;

    if(checkMonth(month_age)){
	month_age=0;
	startAge++;
      }

      
  }

  for(int i=1;i<=retired_months;i++){

    printf("Age %3d month %2d you have $%.2f\n",startAge,month_age,initial);
    
    initial=accountPlus(retired,initial);

    month_age++;

    if(checkMonth(month_age)){
	month_age=0;
	startAge++;
      }



      
  }

  return;
  
}


int main(void) {

  retire_info working;
  working.months= 489;
  working.contribution= 1000;
  working.rate_of_return= 0.045;

  retire_info retired;
  retired.months= 384;
  retired.contribution= -4000;
  retired.rate_of_return= 0.01;

  int startAge=327;
  double initial=21345;
  
  retirement(startAge,initial,working,retired);
  
  return EXIT_SUCCESS;
}
