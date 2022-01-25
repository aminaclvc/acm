#include <iostream>
#include <vector>
#include <cmath>

int main(void) {
    int n = 0;
    int counter = 1;

    while (std::cin >> n) {
        std::cout << "Case " << counter << ":" << std::endl;
        counter++;

        std::vector<int> numbers;
        numbers.resize(n);

        for (int i = 0; i < n; i++) {
            std::cin >> numbers[i];
        }

        int m;
        std::cin >> m;

        for (int i = 0; i < m; i++) {
            int target;
            std::cin >> target;
            int closest = numbers[0] + numbers[1];

            for (int j = 0; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int sum = numbers[j] + numbers[k];
                    if (abs(sum - target) < abs(closest - target)) {
                        closest = sum;
                    }
                }
            }
            std::cout << "Closest sum to " << target << " is " << closest << "." << std::endl;
        }
    }
    return 0;
}