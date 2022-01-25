#include <iostream>
#include <vector>


int main(void) {
    int n, k;
    std::cin >> n >> k;

    std::vector<bool> sieve;
    sieve.resize(n + 1, true);

    sieve[0] = false;
    sieve[1] = false;

    int crossed = 0;

    for (int i = 2; i <= n; i++) {
        if (!sieve[i]) {
            continue;
        }

        for (int j = i; j <= n; j += i) {
            if (!sieve[j]) {
                continue;
            }

            sieve[j] = false;
            crossed++;

            if (crossed == k) {
                std::cout << j << std::endl;
                return 0;
            }
        }
    }
    return 0;
}