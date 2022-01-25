/* Amina Colovic
* Kattis Problem: Rational Arithmetic
* Problem ID: rationalarithmetic
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 3.5
* Language: C++
*/

#include <iostream>

typedef long long ll;

ll gcd(ll a, ll b)
{
  if (a == 0)
  {
      return b;
  }
  return gcd(b % a, a);
}

void print(ll num, ll den)
{
  bool pos = (num > 0 && den > 0) || (num < 0 && den < 0);

  if (num < 0)
  {
      num = -num;
  }
  if (den < 0)
  {
      den = -den;
  }

  ll d = gcd(num, den);

  num /= d, den /= d;

  if (num == 0 || den == 0)
  {
      std::cout << "0 / 1" << std::endl;
  }
  else
  {
      std::cout << (pos ? "" : "-") << num << " / " << den << std::endl;
  }
}

void addSub(ll x1, ll y1, ll x2, ll y2, int state)
{
  ll num = x1 * y2 + state * x2 * y1;
  ll den = y1 * y2;
  print(num, den);
}

void mul(ll x1, ll y1, ll x2, ll y2)
{
  ll num = x1 * x2;
  ll den = y1 * y2;
  print(num, den);
}

int main()
{
  int t;
  std::cin >> t;

  while (t--)
  {
      ll x1, y1, x2, y2;
      char operation;

      std::cin >> x1 >> y1 >> operation >> x2 >> y2;

      if (operation == '+')
      {
          addSub(x1, y1, x2, y2, 1);
      }
      else if (operation == '-')
      {
          addSub(x1, y1, x2, y2, -1);
      }
      else if (operation == '/')
      {
          mul(x1, y1, y2, x2);
      }
      else
      {
          mul(x1, y1, x2, y2);
      }
  }
  return 0;
}
