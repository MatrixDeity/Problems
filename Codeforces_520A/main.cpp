#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    unordered_set<char> us;
    for (char c : str) {
        us.insert(tolower(c));
    }
    cout << (us.size() == 26 ? "YES" : "NO");
    return 0;
}
