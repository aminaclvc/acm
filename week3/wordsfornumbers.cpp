/* Amina Colovic
* Kattis Problem: Words for Numbers
* Problem ID: wordsfornumbers
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 2.5
* Language: C++
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <map>

std::map<int, std::string> m1{
  {0,"zero"},
  {1, "one"},
  {2, "two"},
  {3, "three"},
  {4, "four"},
  {5, "five"},
  {6, "six"},
  {7, "seven"},
  {8, "eight"},
  {9, "nine"},
  {10,"ten"},
  {11, "eleven"},
  {12, "twelve"},
  {13, "thirteen"},
  {14, "fourteen"},
  {15, "fifteen"},
  {16, "sixteen"},
  {17, "seventeen"},
  {18, "eighteen"},
  {19, "nineteen"},
};

std::map<int, std::string> m2{
  {0, ""},
  {1, ""},
  {2, "twenty"},
  {3, "thirty"},
  {4, "forty"},
  {5, "fifty"},
  {6, "sixty"},
  {7, "seventy"},
  {8, "eighty"},
  {9, "ninety"},
};

bool isNumber(std::string s) {
  bool retVal = false;
  for (int i = 0; i < s.length(); i++) {
    if (std::isdigit(s[i])) {
      retVal = true;
    }
    else {
      retVal = false;
    }
  }
  return retVal;
}

int main() {
  while (true) {
    int words = 0;
    std::string input;
    std::string out = std::string();
    std::string w = std::string();
    std::getline(std::cin, input);
    std::istringstream istring(input);

    if (std::cin.eof()) {
      return(0);
    }

    while (istring >> w) {
      words++;
      if (isNumber(w)) {
        int tmp = 0;
        tmp = std::stoi(w, nullptr, 0);
        if (tmp < 20) {
          out += m1[tmp];
        }
        else {
         out += m2[tmp / 10] + ((tmp % 10) ? ('-' + m1[tmp % 10]) : std::string());
        }
        if (words == 1) {
          out[0] = std::toupper(out[0]);
        }
      }
      else {
        out += w;
      }
      out += ' ';
    }
    out.pop_back();
    std::cout << out << std::endl;
  }

  return 0;
}
