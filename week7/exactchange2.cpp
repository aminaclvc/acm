/* Amina Colovic
* Kattis Problem: Exact Change
* Problem ID: exactchange2
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 4.6
* Language: C++
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10000

int main(void) {
    int testCases = 0;
    std::cin >> testCases;

    while (testCases--) {
        int price = 0;
        std::cin >> price;

        int numBills;
        std::cin >> numBills;

        std::vector<int> bills(numBills, 0);
        for (int i = 0; i < numBills; i++) {
            std::cin >> bills[i];
        }

        std::vector<int> dp(MAX + 1, 10000);
        dp[0] = 0;

        for (int i = 0; i < numBills; i++) {
            for (int j = MAX; j >= 0; j--) {
                if ((j - bills[i] >= 0) && (dp[j - bills[i]] + 1 < dp[j]))
                    dp[j] = dp[j - bills[i]] + 1;
            }
        }

        int i;
        for (i = price; dp[i] == MAX; i++);

        std::cout << i << " " << dp[i] << std::endl;
    }
    return 0;
}
