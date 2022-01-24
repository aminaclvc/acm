/* Amina Colovic
* Kattis Problem: Take Two Stones
* Problem ID: twostones
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 1.3
* Language: C
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int stones = 0;

  scanf("%d", &stones);

  if((stones%2) == 0)
  {
      printf("Bob\n");

  }
  else
  {
      printf("Alice\n");
  }
    
}
