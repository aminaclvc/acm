/* Amina Colovic
* Kattis Problem: Tarifa
* Problem ID: tarifa
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 1.3
* Language: C
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
  int credit, month, consumptions = 0;

  scanf("%d", &credit);
  scanf("%d", &month);

  for (int i = 0; i < month; i++)
  {
      int temp;
      scanf("%d",&temp);
      consumptions += temp;
  }
  printf("%d\n", ((credit * month) - consumptions) + credit);
  
  return 0;
}
