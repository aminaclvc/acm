#include <iostream>

int main() {
    int n, p;
    int max = 0, maxLocal = 0;

    std::cin >> n >> p;
    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;

        tmp -= p;

        if (tmp > (tmp + max)) {
            max = tmp;
        }
        else {
            max = tmp + max;
        }

        if (max > maxLocal) {
            maxLocal = max;
        }
    }

    std::cout << maxLocal << std::endl;
    return 0;
}