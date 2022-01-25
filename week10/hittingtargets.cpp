/* Amina Colovic
* Kattis Problem: Hitting Targets
* Problem ID: hittingtargets
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 1.6
* Language: C++
*/

#include <iostream>
#include <vector>
#include <utility>

struct rectangle {
    int x1;
    int y1;
    int x2;
    int y2;
};

struct circle {
    int x;
    int y;
    int r;
};

int main(void) {
    int numTargets = 0;
    std::cin >> numTargets;

    std::string shape;
    std::vector<rectangle> rectList;
    std::vector<circle> circList;

    for (int i = 0; i < numTargets; i++) {
        std::cin >> shape;
        if (shape == "rectangle") {
            rectangle rect;
            std::cin >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2;
            rectList.push_back(rect);
        }
        else if (shape == "circle") {
            circle circ;
            std::cin >> circ.x >> circ.y >> circ.r;
            circList.push_back(circ);
        }
    }
    int numShots = 0;
    std::cin >> numShots;

    while (numShots--) {
        int hits = 0;
        int x, y;
        std::cin >> x >> y;

        for (int i = 0; i < rectList.size(); i++) {
            if (x >= rectList[i].x1 && x <= rectList[i].x2 && y >= rectList[i].y1 && y <= rectList[i].y2) {
                hits++;
            }
        }
        // Kreisgleichung: x^2 + y^2 = r^2
        for (int i = 0; i < circList.size(); i++) {
            int dX = x - circList[i].x; //delta x
            int dY = y - circList[i].y; // delta y
            if (dX * dX + dY * dY <= circList[i].r * circList[i].r) {
                hits++;
            }
        }
        std::cout << hits << std::endl;
    }

    return 0;
}