/* Amina Colovic
* Kattis Problem: Pot
* Problem ID: pot
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 1.3
* Language: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int n = 0;
  int num = 0;
  int sum = 0;

  scanf("%d",&n);

  for (int i = 0; i < n; i++)
  {
      scanf("%d", &num);
      sum += pow((num/10), (num%10));
  }
  printf("%d\n", sum);
}
