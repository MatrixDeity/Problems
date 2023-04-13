/**
    LeetCode_71
    https://leetcode.com/problems/simplify-path/
    MatrixDeity, 2023.
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        auto n = path.size();
        vector<string> st;

        for (size_t i = 0; i < n; ++i) {
            if (path[i] == '/') {
                continue;
            }

            string token;
            while (i < n && path[i] != '/') {
                token.push_back(path[i++]);
            }

            if (token == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else if (token == ".") {
                continue;
            } else {
                st.push_back(token);
            }
        }

        string res;
        for (const auto& item : st) {
            res.push_back('/');
            res.append(move(item));
        }

        return res.empty() ? "/" : res;
    }
};
