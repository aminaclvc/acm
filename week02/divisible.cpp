/* Amina Colovic
* Kattis Problem: Divisible Subsequences
* Problem ID: divisible
* CPU Time limit: 3 sec
* Memory limit: 1024 MB
* Difficulty: 3.7
* Language: C++
*/

#include <bits/stdc++.h>

const int max = 1000000;

int main() {
  int cases = 0;

  std::cin >> cases;

  while(cases --) {
      int d = 0;
      int n = 0;
      int sequence[max];

      std::cin >> d >> n;

      memset(sequence, 0, sizeof(sequence));
      sequence[0] = 1;

      int sum = 0;
      for(int i = 0; i < n; i++) {
          int tmp = 0;
          std::cin >> tmp;
          sum += tmp;
          sum %= d;
          sequence[sum]++;
      }

      int res = 0;
      for(int j = 0; j < d; j++) {
          if( sequence[j] > 0 ){
              res += sequence[j] * (sequence[j] - 1) / 2;
          }
      }
      std::cout << res << std::endl;
  }
  return 0;
}
