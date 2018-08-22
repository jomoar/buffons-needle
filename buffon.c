#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* PARAMETERS
 * 
 * l - length of the thrown needles
 * d - spacing between lines
 * N - number of throws
 *
 * VARIABLES
 *
 * n - counter for number of line crossings
 * x - distance from the needle's middle point to the closest line - between 0 and d/2
 * theta - acute angle between the needle and closest line - between 0 and pi/2
 *
 */

int main( int argc, char *argv[] ) {
  
  if ( argc != 4 ) { 
    printf("\x1b[31m""Usage: buffon [l] [d] [N]\n""\x1b[0m");
  }
  else {

    double l;
    double d;
    int N;
    double x;
    double theta;
    double P;
    int n;

    l = strtod(argv[1], NULL);
    d = strtod(argv[2], NULL);
    N = strtol(argv[3], NULL, 10);
    n = 0;
    
    /* THROWS
     * 
     * for each throw picks a random value for x and theta and increments n if line crossing occurs
     *
     */
    for ( int i = 0; i < N; i++ ) {
      
      x = ( (double)rand()/RAND_MAX ) * (d/2);
      theta = ( (double)rand()/RAND_MAX ) * M_PI/2;
      
      if ( x <= (l/2) * sin(theta) ) {
        
        n++; }
    }
    
    /* RESULT */
    P = ( (double)n )/N;
    printf("%f\n", P);

    return P;
  }
  
  return 1;
}
