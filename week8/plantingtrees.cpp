/* Amina Colovic
* Kattis Problem: Planting Trees
* Problem ID: plantingtrees
* CPU Time limit: 3 sec
* Memory limit: 1024 MB
* Difficulty: 1.8
* Language: C++
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

int main(void)
{
  int n = 0;

  std::vector<int> v{};

  std::cin >> n;

  for (auto i = 0; i < n; i++)
  {
    int t = 0;
    std::cin >> t;
    v.push_back(t);
  }

  std::sort(v.begin(), v.end(), std::greater<int>());

  for (auto i = 0; i < n; i++)
  {
    v[i] +=i+1+1;
  }
  std::sort(v.begin(), v.end(), std::greater<int>());
  std::cout << v.front() << std::endl;

  return 0;
}
