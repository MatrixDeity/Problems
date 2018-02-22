#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    unordered_set<int> us;
    for (int i = 0; i < 10; ++i) {
        int a;
        cin >> a;
        us.insert(a);
    }
    int n;
    cin >> n;
    vector<int> vec(6);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> vec[j];
        }
        int cnt = 0;
        for (int j = 0; j < 6; ++j) {
            if (us.count(vec[j]) != 0)
                ++cnt;
        }
        if (cnt >= 3)
            cout << "Lucky\n";
        else
            cout << "Unlucky\n";
    }
    return 0;
}
