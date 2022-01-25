/* Amina Colovic
* Kattis Problem: Geppetto
* Problem ID: geppetto
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 3.0
* Language: C++
*/


#include <iostream>
#include <vector>
#include <utility>

int main() {
  int ingredients, pairs;
  std::cin >> ingredients >> pairs;
  std::vector< std::pair<int, int> > constraints;
  while (pairs--) {
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    std::pair<int, int> tmp;
    tmp.first = a;
    tmp.second = b;
    constraints.push_back(tmp);
  }
  int res = 0;
  for (int bit = 0; bit < (1 << ingredients); bit++) {
    bool isValid = true;
    for (auto& p : constraints) {
      if ((bit & (1 << p.first)) && (bit & (1 << p.second))) {
        isValid = false;
        break;
      }
    }
    if (isValid) res++;
  }
  std::cout << res << std::endl;

  return 0;
}
