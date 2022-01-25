/* Amina Colovic
* Kattis Problem: Polygon Area
* Problem ID: polygonarea
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 3.0
* Language: C++
*/

#include <iostream>
#include <vector>
#include <utility>

int determinant(std::pair<int, int> v1, std::pair<int, int> v2) {
    return (v1.first * v2.second) - (v1.second * v2.first);
}

int main(void) {
    int numVertices = 0;

    while (std::cin >> numVertices) {
        if (numVertices == 0) break;

        std::vector<std::pair<int, int>> verticesList(numVertices);
        for (int i = 0; i < numVertices; i++) {
            int x, y;
            std::cin >> x >> y;
            verticesList[i].first = x;
            verticesList[i].second = y;
        }

        int sum = 0;
        for (int i = 0; i < numVertices - 1; i++) {
            sum += determinant(verticesList[i], verticesList[i + 1]);
        }
        sum += determinant(verticesList[numVertices - 1], verticesList[0]);

        if (sum < 0) {
            printf("CW %.1f\n", -sum / 2.0);
        }
        else {
            printf("CCW %.1f\n", sum / 2.0);
        }
    }
    return 0;
}