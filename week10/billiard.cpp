/* Amina Colovic
* Kattis Problem: Billiard
* Problem ID: billiard
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 1.8
* Language: C++
*/
#include <iostream>
#include <cmath>

int main(void) {
    int horizontal = 0;
    int vertical = 0;
    int seconds = 0;
    int verticalBounces = 0;
    int horizontalBounces = 0;

    while (std::cin >> horizontal >> vertical >> seconds >> verticalBounces >> horizontalBounces) {
        if (horizontal == 0 && vertical == 0 && seconds == 0 && verticalBounces == 0 && horizontalBounces == 0) break;

        double distX = horizontal * verticalBounces;
        double distY = vertical * horizontalBounces;

        double dist_total = sqrt(distX * distX + distY * distY);
        double velocity = dist_total / seconds;
        double angle = 180.0 * acos(distX / dist_total) / M_PI;

        printf("%.2f %.2f\n", angle, velocity);
    }
    return 0;
}