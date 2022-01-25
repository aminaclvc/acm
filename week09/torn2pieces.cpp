/* Amina Colovic
* Kattis Problem: Torn To Pieces
* Problem ID: torn2pieces
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 3.0
* Language: C++
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <queue>

std::multimap<std::string, std::string> routes;
std::map<std::string, std::string> res;
std::map<std::string, bool> check;

void bfs(std::string start, std::string end) {
    std::queue<std::string> que;

    que.push(start);
    std::string curr, tmp;
    bool flag = false;
    check[start] = true;
    while (!que.empty()) {
        curr = que.front();
        que.pop();

        if (curr == end) {
            flag = true;
            break;
        }
        std::multimap<std::string, std::string>::iterator it;
        for (it = routes.equal_range(curr).first; it != routes.equal_range(curr).second; ++it) {
            std::string tmpEnd = (*it).second;
            if (check[tmpEnd])
                continue;

            check[tmpEnd] = true;

            que.push(tmpEnd);
            res[tmpEnd] = curr;
        }
    }

    if (flag) {
        std::vector<std::string> re;
        re.push_back(end);
        while (!res[end].empty()) {
            re.push_back(res[end]);
            end = res[end];
        }

        for (int i = re.size() - 1; i >= 0; i--) {
            if (i == re.size() - 1) {
                std::cout << re[i];
            }
            else {
                std::cout << " " << re[i];
            }
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "no route found" << std::endl;
    }
}

int main() {
    int numPieces = 0;
    std::cin >> numPieces;

    routes.clear();
    res.clear();
    check.clear();

    std::string tmp;
    std::string start, end;
    getline(std::cin, tmp);

    for (int i = 0; i < numPieces; i++) {
        getline(std::cin, tmp);
        std::istringstream iss(tmp);

        iss >> start;
        check[start] = false;
        while (iss >> end) {
            routes.insert(std::pair<std::string, std::string>(start, end));
            routes.insert(std::pair<std::string, std::string>(end, start));
        }
    }

    std::cin >> start >> end;
    bfs(start, end);
    return 0;
}
