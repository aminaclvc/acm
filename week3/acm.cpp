/* Amina Colovic
* Kattis Problem: ACM Contest Scoring
* Problem ID: acm
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 1.5
* Language: C++
*/

#include <iostream>
#include <string>
#include <sstream>
#include <map>

int main() {
  int solvedProblems = 0;
  int totalTime = 0;
  std::map<char, int> wrongProblems;

  while (true) {
    int time;
    char problem;
    std::string status;

    std::cin >> time;
    if (time == -1) {
        break;
    }
    std::cin >> problem >> status;
    if (status == "wrong") {
        wrongProblems[problem]++;
    }
    else {
      solvedProblems++;
      totalTime += time;

      if (wrongProblems[problem] > 0) {
          totalTime += 20 * wrongProblems[problem];
      }
    }
  }
  std::cout << solvedProblems << " " << totalTime << std::endl;
  return 0;
}
