/* Amina Colovic
* Kattis Problem: Fundamental Neighbors
* Problem ID: fundamentalneighbors
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 4.4
* Language: C++
*/

#include <iostream>
#include <unordered_map>
#include <cmath>

std::unordered_map<int, int> factorization(int n)
{
  std::unordered_map<int, int> factors;
  while (n % 2 == 0)
  {
      factors[2]++;
      n = n/2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2)
  {
      while (n % i == 0)
      {
          factors[i]++;
          n = n/i;
      }
  }
  if (n > 2){
      factors[n]++;
  }
  return factors;
}

int main()
{
  while (true)
  {
      int n = 0;
      std::cin >> n;

      if(std::cin.eof()){
          break;
      }
      else
      {
          std::unordered_map<int, int> myFactors = factorization(n);
          int res = 1;
          for(auto elem : myFactors){
              res *= pow(elem.second, elem.first);
          }
          std::cout << n << " " << res << std::endl;

      }

  }


  return 0;
}
