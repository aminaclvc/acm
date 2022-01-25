/* Amina Colovic
* Kattis Problem: Planina
* Problem ID: planina
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 1.3
* Language: C
*/

#include <stdio.h>
#include <stdalign.h>
#include <math.h>

int main(void)
{
  int n = 0;
  int res = 0;

  scanf("%d", &n);
  res = (int) pow((pow(2, n) + 1),2);
  printf("%d\n", res);
}
