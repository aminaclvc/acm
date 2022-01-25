/* Amina Colovic
* Kattis Problem: Mixed Fractions
* Problem ID: mixedfractions
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 1.6
* Language: C++
*/

#include <iostream>

int main()
{
  int numerator;
  int denominator;

  while (true)
  {
      std::cin >> numerator >> denominator;
      if (numerator == 0 && denominator == 0)
      {
          break;
      }
      else
      {
          int quotient = numerator / denominator;
          int reminder = numerator % denominator;
          std::cout << quotient << " " << reminder << " / " << denominator << std::endl;
      }
  }

  return 0;
}
