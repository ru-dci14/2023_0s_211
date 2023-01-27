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
  }  //Newest version 9:07pm

  char buf[256];

  char* string = fgets(buf, 256, fp);
  int a = atoi(string);

  string = fgets(buf, 256, fp);
  int b = atoi(string); 

  //If the input file has more than 2 numbers 
  if(fgets(buf, 256, fp) != NULL)
  {
    printf("Invalid input\n"); 
    return EXIT_FAILURE; 
  }
  else
  {

    int ans = -1; 

    printf("Int a = %d\nInt b = %d\n", a, b); 

    //If the input ints a,b are negative or zero, exit the program
    if(a <= 0 || b <= 0)
    {
      printf("A or B is invalid\n"); 
      return EXIT_FAILURE; 

    }
    else if(a > b)
    {
      printf("Inside else if in ln 52\n"); 
      ans = root(a, b);
      printf("Answer = %d\n", ans);
    }
    else
    {
      printf("Inside else in ln 58\n"); 
      ans = root(b, a); 
      printf("Answer = %d\n", ans);
    }
    
    printf("Here after the if/else\n"); 
    return EXIT_SUCCESS;

  }

}

int root(int a, int b) //a will always be greater than b 
{
  //Check if a^2 + b^2 = c^2 
  //If not, check if c^2 - a^2 = b^2

  printf("insider root function\n"); 
  int aSquared = a*a; 
  int bSquared = b*b; 
  int cSquared = aSquared + bSquared; 
  int c = sqrt(cSquared); 
  int dSquared = aSquared - bSquared;
  int d = sqrt(dSquared); 


  if((c*c) == cSquared) //Check if c^2 = a^2 + b^2
  {
    return c; 
  }
  else if((d*d) == dSquared) //Check if b^2 = c^2 - a^2
  {
    return d;
  }
  else 
    return -1; 
}