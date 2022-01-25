/* Amina Colovic
* Kattis Problem: Quick Brown Fox
* Problem ID: quickbrownfox
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 1.5
* Language: C++
*/

#include <iostream>
#include <string>
#include <vector>

int main()
{
  int n;
  std::cin >> n;
  std::cin.ignore();
  for (int i = 0; i < n; i++)
  {
    std::vector<bool> letters;
    letters.resize(26, false);

    std::string input;
    std::getline(std::cin, input);

    int usedLetters = 0;

    for (auto c : input)
    {
      int tmp = tolower(c) - 'a';
      if (tmp < 26 && tmp >= 0 && !letters[tmp])
      {
          letters[tmp] = true;
          usedLetters++;
      }
    }

    if (usedLetters == 26)
    {
      std::cout << "pangram" << std::endl;
    }
    else
    {
      std::cout << "missing ";
      for (int j = 0; j < 26; j++)
      {
        if (!letters[j])
        {
            std::cout << (char)(j + 'a');
        }
      }
    }
    std::cout << std::endl;
  }
  return 0;
}
