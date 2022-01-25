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