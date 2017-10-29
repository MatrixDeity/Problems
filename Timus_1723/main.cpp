/**
    Timus_1723
    http://acm.timus.ru/problem.aspx?space=1&num=1723
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    unordered_map<char, int> um;
    string str;
    cin >> str;
    for (char chr : str) {
        ++um[chr];
    }
    auto comp = [] (pair<const char, int>& l, pair<const char, int>& r) {
        return l.second < r.second;
    };
    cout << max_element(um.begin(), um.end(), comp)->first;
    return 0;
}
