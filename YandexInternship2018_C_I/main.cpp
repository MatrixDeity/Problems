#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

using namespace std;

using NodePtr = shared_ptr<class Node>;

struct Node {
    unordered_map<char, NodePtr> um;
    int cnt = 0;
    bool word = false;
};

bool hasNode(NodePtr root, string& str) {
    for (char c : str) {
        if (root->um[c] == nullptr)
            return false;
        root = root->um[c];
    }
    return root->word;
}

void insertNode(NodePtr root, string& str) {
    for (char c : str) {
        if (root->um[c] == nullptr) {
            root->um[c] = make_shared<Node>();
        }
        root = root->um[c];
        ++root->cnt;
    }
    root->word = true;
}

int calcPath(NodePtr root, string& str) {
    int res = 0;
    for (char c : str) {
        ++res;
        if (root->um[c]->cnt == 1)
            break;
        root = root->um[c];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    NodePtr dict = make_shared<Node>();
    int n, ans = 0;;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        if (hasNode(dict, str)) {
            ans += calcPath(dict, str);
        } else {
            ans += str.size();
            insertNode(dict, str);
        }
    }
    cout << ans;
    return 0;
}
