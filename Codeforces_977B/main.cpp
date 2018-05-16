#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string str;
    unordered_map<string, int> um;
    cin >> n >> str;
    for (int i = 0; i < n - 1; ++i) {
        ++um[str.substr(i, 2)];
    }
    auto ans = *max_element(um.begin(), um.end(), [] (const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
    });
    cout << ans.first;
    return 0;
}
