#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Node {
    int cnt = 0;
    bool word = false;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<string, Node> um;
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        int len = str.size();
        if (um[str].word) {
            while (!str.empty() && um[str].cnt == 1) {
                --len;
                str = str.substr(0, str.size() - 1);
            }
            ++len;
        } else {
            um[str].word = true;
            while (!str.empty()) {
                ++um[str].cnt;
                str = str.substr(0, str.size() - 1);
            }
        }
        ans += len;
    }
    cout << ans;
    return 0;
}
