/* Amina Colovic
* Kattis Problem: Big Truck
* Problem ID: bigtruck
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 3.0
* Language: C++
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INF 1073741824

struct node {
    int destination;
    int distance;
    int locations;
};

bool operator<(const node& n1, const node& n2) {
    if (n1.distance == n2.distance) {
        return n1.locations < n2.locations;
    }
    return n1.distance > n2.distance;
}

int main(void) {
    int numLocations = 0;
    std::cin >> numLocations;

    std::vector<int> locations(numLocations);
    for (auto& i : locations) {
        std::cin >> i;
    }
    int numRoads = 0;
    std::cin >> numRoads;

    std::vector<std::vector<std::pair<int, int>>> roads(numLocations); //destination, weight
    for (int i = 0; i < numRoads; i++) {
        int location1, location2, items;
        std::cin >> location1 >> location2 >> items;
        location1--; location2--;


        roads[location1].push_back({ location2,items });
        roads[location2].push_back({ location1,items });
    }

    std::vector<int> shortesRoute(numLocations, INF);
    std::vector<int> bestLocations(numLocations, 0);
    std::vector<bool> visited(numLocations, false);

    std::priority_queue<node> que;

    que.push({ 0,0,locations[0] });
    shortesRoute[0] = 0;
    bestLocations[0] = locations[0];

    while (!que.empty()) {
        int curr = que.top().destination;
        que.pop();

        if (visited[curr]) {
            continue;
        }
        visited[curr] = true;

        for (auto i : roads[curr]) {
            int next = i.first;

            if (shortesRoute[next] > shortesRoute[curr] + i.second) {
                shortesRoute[next] = shortesRoute[curr] + i.second;
                bestLocations[next] = bestLocations[curr] + locations[next];
                que.push({ next,shortesRoute[next],bestLocations[next] });
            }

            else if (shortesRoute[next] == shortesRoute[curr] + i.second) {
                bestLocations[next] = std::max(bestLocations[next], bestLocations[curr] + locations[next]);
                que.push({ next,shortesRoute[next],bestLocations[next] });
            }
        }
    }

    if (shortesRoute[numLocations - 1] >= INF) {
        std::cout << "impossible" << std::endl;
    }
    else {
        std::cout << shortesRoute[numLocations - 1] << " " << bestLocations[numLocations - 1] << std::endl;
    }
    return 0;
}