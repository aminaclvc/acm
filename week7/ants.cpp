/* Amina Colovic
* Kattis Problem: Ants
* Problem ID: ants
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 2.3
* Language: C++
*/

#include <iostream>
#include <vector>
#include <climits>

int main(void) {
    int testCases = 0;
    std::cin >> testCases;
    while (testCases--) {
        int lengthPole = 0;
        int numAnts = 0;
        std::cin >> lengthPole >> numAnts;

        std::vector<int> positions(numAnts, 0);
        for (int i = 0; i < numAnts; i++) {
            std::cin >> positions[i];
        }
        int earliest = INT_MAX;
        int latest = 0;
        int half = lengthPole / 2;
        for (int position : positions) {
            if (position <= half) {
                if (position < earliest) {
                    earliest = position;
                }
                if (position > latest) {
                    latest = position;
                }
            }
            else if (position > half) {
                int newPosition = lengthPole - position;
                if (newPosition < earliest) {
                    earliest = newPosition;
                }
                if (newPosition > latest) {
                    latest = newPosition;
                }
            }
        }
        std::cout << latest << " " << lengthPole - earliest << std::endl;
    }
    return 0;
}
