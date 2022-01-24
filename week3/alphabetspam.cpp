/* Amina Colovic
* Kattis Problem: Alphabet Spam
* Problem ID: alphabetspam
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 1.4
* Language: C++
*/

#include <cctype>
#include <iostream>
#include <cstring>

int main()
{
  std::string input;
  std::cin >> input;

  int whiteSpace = 0;
  int lowerCase = 0;
  int upperCase = 0;
  int symbols = 0;

  for (int i = 0; i < input.size(); i++)
  {
      if (input[i] == '_')
      {
          whiteSpace++;
      }
      else if (islower(input[i]))
      {
          lowerCase++;
      }
      else if (isupper(input[i]))
      {
          upperCase++;
      }
      else
      {
          symbols++;
      }
  }

  int size = input.size();

  double w = (double)whiteSpace / size;
  double l = (double)lowerCase / size;
  double u = (double)upperCase / size;
  double s = (double)symbols / size;

  printf("%.16f\n", w);
  printf("%.16f\n", l);
  printf("%.16f\n", u);
  printf("%.16f\n", s);

  return 0;
}
