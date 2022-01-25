/* Amina Colovic
* Kattis Problem: Honeycomb Walk
* Problem ID: honey
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 2.5
* Language: C++
*/

#include <iostream>

int depth = 16;
int moves[16][16][16];
int stepNum;

#define MAX 14

void preprocess(int list[]) {
    moves[0][8][8] = 1;
    for (int n = 1; n <= MAX; n++) {
        for (int i = 1; i <= depth; i++) {
            for (int j = 1; j <= depth; j++) {
                moves[n][i][j] = moves[n - 1][i][j + 1] + moves[n - 1][i][j - 1] + moves[n - 1][i + 1][j] + moves[n - 1][i - 1][j] + moves[n - 1][i + 1][j - 1] + moves[n - 1][i - 1][j + 1];
            }
        }
        list[n] = moves[n][8][8];
    }
}

int main() {
    int list[15];
    preprocess(list);
    int testCases = 0;
    std::cin >> testCases;
    while (testCases--) {
        int n = 0;
        std::cin >> n;
        std::cout << list[n] << std::endl;

    }
    return 0;
}
