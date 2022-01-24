/* Amina Colovic
* Kattis Problem: Number Sets
* Problem ID: numbersetseasy
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 4.4
* Language: C++
*/

#include <iostream>
#include <vector>
#include <set>
#include <cmath>

int find(std::vector<int> &d, int a)
{
  if (d[a] == -1)
  {
      return a;
  }
  return d[a] = find(d, d[a]);
}

void join(std::vector<int> &d, int a, int b)
{
  a = find(d, a);
  b = find(d, b);
  if (a == b)
      return;
  d[a] = b;
}

std::set<int> factorization(int n)
{
  std::set<int> primes;

  for (int i = 2; i <= sqrt(n); i++)
  {
      while (n % i == 0)
      {
          primes.insert(i);
          n /= i;
      }
  }

  if (n > 1)
  {
      primes.insert(n);
  }

  return primes;
}

bool share(int a, int b, int p)
{
  std::set<int> factorsa = factorization(a);
  std::set<int> factorsb = factorization(b);

  for (auto i : factorsa)
  {
      if (i >= p && factorsb.count(i) > 0)
      {
          return true;
      }
  }

  return false;
}

int solve()
{
  int a, b, p;
  std::cin >> a >> b >> p;

  std::vector<int> d(b + 1, -1);

  for (int i = a; i <= b; i++)
  {
      for (int j = i + 1; j <= b; j++)
      {
          if (share(i, j, p))
          {
              join(d, i, j);
          }
      }
  }

  int sets = 0;
  for (int i = a; i <= b; i++)
  {
      if (d[i] == -1)
      {
          sets++;
      }
  }

  return sets;
}

int main()
{
  int cases;
  std::cin >> cases;
  for (int i = 1; i <= cases; i++)
  {
      std::cout << "Case #" << i << ": " << solve() << std::endl;
  }

  return 0;
}
