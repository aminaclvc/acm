/* Amina Colovic
* Kattis Problem: Convex Polygon Area
* Problem ID: convexpolygonarea
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 1.9
* Language: C++
*/

#include <iostream>
#include <vector>
#include <utility>

/* Area of a Convex Polygon
The coordinates (x1, y1), (x2, y2), (x3, y3), . . . , (xn, yn) of a convex polygon
are arranged in the "determinant" below. The coordinates must be taken
in counterclockwise order around the polygon, beginning and ending at the same point.
more info: https://www.mathwords.com/a/area_convex_polygon.htm
*/

int determinant(std::pair<int, int> v1, std::pair<int, int> v2) {
    return (v1.first * v2.second) - (v1.second * v2.first);
}

int main(void) {
    int numPolygon = 0;
    std::cin >> numPolygon;

    while (numPolygon--) {
        int numVertices = 0;
        std::cin >> numVertices;
        std::vector<std::pair<int, int>> vertices(numVertices);
        for (int i = 0; i < numVertices; i++) {
            int x, y;
            std::cin >> x >> y;
            vertices[i].first = x;
            vertices[i].second = y;
        }

        //Find area of polygon
        // 1/2 * [ (x1y2 + x2y3 + ... + xn-1yn + xny1) - (x2y1 + x3y2 + ... + xnyn-1 + x1yn) ]
        int sum = 0;
        for (int i = 0; i < numVertices - 1; i++) {
            sum += determinant(vertices[i], vertices[i + 1]);
        }
        sum += determinant(vertices[numVertices - 1], vertices[0]);

        printf("%.1f\n", sum / 2.0);
    }
    return 0;
}