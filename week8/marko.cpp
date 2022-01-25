#include <iostream>
#include <unordered_map>
#include <vector>

int main(void) {
    std::unordered_map<char, char> map;
    map['a'] = '2';
    map['b'] = '2';
    map['c'] = '2';
    map['d'] = '3';
    map['e'] = '3';
    map['f'] = '3';
    map['g'] = '4';
    map['h'] = '4';
    map['i'] = '4';
    map['j'] = '5';
    map['k'] = '5';
    map['l'] = '5';
    map['m'] = '6';
    map['n'] = '6';
    map['o'] = '6';
    map['p'] = '7';
    map['q'] = '7';
    map['r'] = '7';
    map['s'] = '7';
    map['t'] = '8';
    map['u'] = '8';
    map['v'] = '8';
    map['w'] = '9';
    map['x'] = '9';
    map['y'] = '9';
    map['z'] = '9';

    int numWords = 0;
    std::cin >> numWords;

    std::vector<std::string>dictionary(numWords, "");
    for (int i = 0; i < numWords; i++) {
        std::cin >> dictionary[i];
    }

    std::string key = "";
    std::cin >> key;

    int res = 0;
    for (int i = 0; i < numWords; i++) {
        if (key.length() != dictionary[i].length()) {
            continue;
        }

        bool valid = true;
        for (int j = 0; j < key.length(); j++) {
            if (key[j] != map[dictionary[i][j]]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            res++;
        }
    }

    std::cout << res << std::endl;

    return 0;
}