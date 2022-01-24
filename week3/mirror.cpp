/* Amina Colovic
* Kattis Problem: Mirror
* Problem ID: mirror
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 1.6
* Language: C++
*/

#include <iostream>
#include <vector>

int main()
{
  int t;
  std::cin >> t;

  for (int i = 0; i < t; i++)
  {
      int r, c;
      std::cin >> r >> c;
      std::vector<std::vector<char> > mirror;
      mirror.resize(r);

      for (int j = 0; j < r; j++)
      {
          for (int k = 0; k < c; k++)
          {
              char tmp;
              std::cin >> tmp;
              mirror[j].push_back(tmp);
          }
      }
      std::cout << "Test " << i + 1 << std::endl;
      for (int l = r - 1; l >= 0; l--)
      {
          for (int m = c - 1; m >= 0; m--)
          {
              std::cout << mirror[l][m];
          }
          std::cout << std::endl;
      }
  }

  return 0;
}
