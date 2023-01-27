/*
Danika Ibarrola

PA 0 - Pythagorean triples 
Given a text file with two ints, the program will return the third int to complete the 
pythagorean triple, or it will return -1 because the input was not a pythagorean triple
*/  

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int root(); 

int main(int argc, char* argv[])
{

  // Open the filename given as the first command line argument for reading
  FILE* fp = fopen(argv[1], "r");
  if (!fp) 
  {
    perror("fopen failed");
    return EXIT_FAILURE;
  }

  char buf[256];

  char* string = fgets(buf, 256, fp);
  int a = atoi(string);

  string = fgets(buf, 256, fp);
  int b = atoi(string); 

  //If the input file has more than 2 numbers 
  if(fgets(buf, 256, fp) != NULL)
  {
    printf("-1"); 
    return EXIT_FAILURE; 
  }
  else
  {
    int ans = -1; 

    //If the input ints a,b are negative or zero, exit the program
    if(a <= 0 || b <= 0)
    {
      printf("-1");
      return EXIT_FAILURE; 
    }
    else if(a > b)
    {
      ans = root(a, b);
      printf("%d\n", ans);
    }
    else
    {
      ans = root(b, a); 
      printf("%d\n", ans);
    }
    
    return EXIT_SUCCESS;
  }

}

int root(int a, int b) //a will always be greater than b 
{
  int aSquared = a*a; 
  int bSquared = b*b; 
  int cSquared = aSquared + bSquared; 
  int c = sqrt(cSquared); 
  int dSquared = aSquared - bSquared;
  int d = sqrt(dSquared); 


  if((c*c) == cSquared) //Check if c^2 = a^2 + b^2
    return c; 
  else if((d*d) == dSquared) //Check if b^2 = c^2 - a^2
    return d;
  else 
    return -1; 
}