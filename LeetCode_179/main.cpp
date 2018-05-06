/**
    LeetCode_179
    https://leetcode.com/problems/largest-number/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ns;
        for (auto item : nums)
            ns.push_back(to_string(item));
        sort(ns.begin(), ns.end(), [] (string& s1, string& s2) {
            return s1 + s2 > s2 + s1;
        });
        string res;
        for (auto& item : ns)
            if (!res.empty() || item != "0")
                res += item;
        return !res.empty() ? res : "0";
    }
};

int main() {
    return 0;
}
