/* Amina Colovic
* Kattis Problem: Magic Trick
* Problem ID: magictrick
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 1.4
* Language: C++
*/

#include <iostream>
#include <unordered_set>

int main(){
  std::unordered_set<char> letters;
  std::string myInput = "";
  std::cin >> myInput;
  int r = 1;

  for (char x : myInput){
      letters.insert(x);
  }

  if (letters.size() != myInput.length())
  {
      r = 0;
  }

  std::cout << r << std::endl;
  return 0;
}
