/* Amina Colovic
* Kattis Problem: Jumbo Javelin
* Problem ID: jumbojavelin
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
      int t = 0;
      std::cin >> t;
      r += t;
  }
  std::cout << r - (n - 1) << std::endl;
  return 0;
}
