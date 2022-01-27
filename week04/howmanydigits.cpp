/* Amina Colovic
* Kattis Problem: How Many Digits?
* Problem ID: howmanydigits
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 3.4
* Language: C++
*/

#include <iostream>
#include <algorithm>
#include <cmath>

int main(void) {
  int n;
  while (scanf("%d", &n) == 1) {
    printf("%d\n", n < 2 ? 1 : (int)ceil(log10(2 * M_PI * n) / 2 + n * (log10(n / M_E))));
  }
  return 0;
}
