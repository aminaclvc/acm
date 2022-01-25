/* Amina Colovic
* Kattis Problem: Kornislav
* Problem ID: kornislav
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 1.4
* Language: C++
*/

#include <iostream>
#include <vector>
#include <algorithm>


int main(void) {
    std::vector<int> v;
    for (int i = 0; i < 4; ++i) {
        int a;
        std::cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    std::cout << (v[0] * v[2]) << std::endl;
    return 0;
}
