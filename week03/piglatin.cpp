/* Amina Colovic
* Kattis Problem: Pig Latin
* Problem ID: piglatin
* CPU Time limit: 3 sec
* Memory limit: 1024 MB
* Difficulty: 2.2
* Language: C++
*/

#include <iostream>
#include <string>
#include <sstream>

bool isVowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

int findFirstVowel(std::string s) {
    int retVal = 0;
    for (int i = 0; i < s.length(); i++) {
      if (isVowel(s[i])) {
        return retVal;
      }
      else {
        retVal++;
      }
    }
    return retVal;
}

std::string formatWord(int posVowel, std::string& s) {
  std::string begin = s.substr(0, posVowel);
  std::string end = s.substr(posVowel, std::string::npos);
  s = end + begin + "ay";
  return s;
}

int main() {
  while (true) {
    std::string input;
    std::getline(std::cin, input);
    int wordCount = 0;

    if (std::cin.eof()) {
      break;
    }
    else {
      std::istringstream istring(input);
      std::string w;

      while (istring >> w) {
        if (findFirstVowel(w) == 0) {
          w += "yay";
          if (wordCount == 0) {
            std::cout << w;
          }
          else {
            std::cout << " " << w;
          }
          wordCount++;
        }
        else {
          w = formatWord(findFirstVowel(w), w);
          if (wordCount == 0) {
            std::cout << w;
          }
          else {
            std::cout << " " << w;
          }
          wordCount++;
        }
      }
      std::cout << std::endl;
    }
  }
  return 0;
}
