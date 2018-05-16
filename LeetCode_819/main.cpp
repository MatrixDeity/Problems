/**
    LeetCode_819
    https://leetcode.com/problems/most-common-word/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> us(banned.begin(), banned.end());
        unordered_map<string, int> um;
        auto begEr = remove_if(paragraph.begin(), paragraph.end(), ::ispunct);
        paragraph.erase(begEr, paragraph.end());
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        stringstream ss(paragraph);
        string word;
        string res;
        int maxCnt = 0;
        while (ss >> word) {
            if (us.count(word) == 0) {
                int cnt = ++um[word];
                if (cnt > maxCnt) {
                    maxCnt = cnt;
                    res = move(word);
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
