#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>

using namespace std;

using NodePtr = shared_ptr<class Node>;

struct Node {
    NodePtr left;
    NodePtr right;
    int max, beg, end;

    Node(int beg, int end) :
        beg(beg), end(end), max(end) {
    }

    bool overlaps(NodePtr node) {
        return beg < node->end && node->beg < end;
    }
};

NodePtr insertNode(NodePtr root, NodePtr node) {
    if (!root)
        return node;
    if (node->beg < root->beg)
        root->left = insertNode(root->left, node);
    else
        root->right = insertNode(root->right, node);
    root->max = max(node->end, root->max);
    return root;
}

bool hasOverlap(NodePtr root, NodePtr node) {
    if (!root)
        return false;
    if (root->overlaps(node))
        return true;
    if (root->left && root->left->max >= node->beg)
        return hasOverlap(root->left, node);
    return hasOverlap(root->right, node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<string, NodePtr> um;
    unordered_map<string, unordered_map<int, vector<string>>> apps;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;
        if (command == "APPOINT") {
            int d, h, m, dur, num;
            char c;
            cin >> d >> h >> c >> m >> dur >> num;
            int beg = d * 24 * 60 + h * 60 + m;
            int end = beg + dur;
            auto node = make_shared<Node>(beg, end);
            vector<string> v(num);
            for (auto& item : v) {
                cin >> item;
            }
            bool fail = false;
            for (auto& item : v) {
                if (hasOverlap(um[item], node)) {
                    if (!fail) {
                        cout << "FAIL\n";
                        fail = true;
                    }
                    cout << item << ' ';
                }
            }
            if (!fail) {
                cout << "OK";
                string tmp = (h < 10 ? "0" : "") + to_string(h) + ':' + (m < 10 ? "0" : "")
                             + to_string(m) + ' ' + to_string(dur);
                for (auto& item : v) {
                    tmp += ' ' + item;
                }
                for (auto& item : v) {
                    um[item] = insertNode(um[item], make_shared<Node>(beg, end));
                    apps[item][d].push_back(tmp);
                }
            }
            cout << '\n';
        } else if (command == "PRINT") {
            int day;
            string name;
            cin >> day >> name;
            sort(apps[name][day].begin(), apps[name][day].end());
            for (auto& str : apps[name][day]) {
                cout << str << '\n';
            }
        }
    }
    return 0;
}
