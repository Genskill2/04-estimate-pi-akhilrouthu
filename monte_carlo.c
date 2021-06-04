#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


float frandom() {
  long int q = random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}
float mc_pi(float i)
{
  float x,y,dist,d;
  int a=0 ;
  for(int n = 0; n<=i; n++)
  {
   float x = frandom();
   float y = frandom();
   float dist = sqrt((x*x) + (y*y));
    if(dist<=1){
      a++;}
  }
  d = (float)(4*a)/i;
  return(d);
}

int main(void) {
  float pi0;
  float pi1;
  
  pi0 = mc_pi(25000);
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);
  
  if (pi0 == pi1) {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
      abort();
    }

  if (fabs(pi0 - pi1) > 0.05) {
      printf("Two separate estimates %f and %f are too different.\n", pi0, pi1);
      abort();
  }

    
  for (int i=2000; i<5000; i++) {
    pi0 = mc_pi(i);
    if (!(fabs(pi0 - M_PI) < 0.4)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi0);
      abort();
    }
  }
}




