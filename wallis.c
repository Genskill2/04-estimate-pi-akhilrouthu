#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>



int main(void) 
{
  float pi;
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}

float wallis_pi(int l)
{
  if(l>0)
  {
  float value = 1; 
  float a,b;
  for(int i = 1; i<=l; i++)
  {
  a =  4(i*i);
  b = (4(i*i)) - 1;
  float c;
  c =  a/b;
 
  value =  value*c;  
  } 
  value = value*2;
  return value;
  }  
}
