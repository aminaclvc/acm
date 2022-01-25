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

#define E 2.718281828459045235360287471352662497757247093699959574966967627724076630353
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

int main(void){
  int n;
  while(scanf("%d",&n) == 1){
    printf("%d\n", n < 2 ? 1 : (int)ceil(log10(2*PI*n)/2+n*(log10(n/E))));
  }
  return 0;
}
