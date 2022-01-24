/* Amina Colovic
* Kattis Problem: N-sum
* Problem ID: nsum
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 1.3
* Language: C++
*/

#include <iostream>

int main(){
  int n = 0;
  int r = 0;
  std::cin >> n;

  for(int i = 0; i < n; i++){
      int tmp = 0;
      std::cin >> tmp;
      r += tmp;
  }
  std::cout << r << std::endl;
  return 0;
}
