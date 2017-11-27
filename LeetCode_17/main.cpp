/**
    LeetCode_17
    https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return vector<string>();

        int n = (int) digits.size();
        const vector<string> SAMPLES = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> res = { "" };
        for (int i = 0; i < n; ++i) {
            int dig = digits[i] - '0';
            const string& samp = SAMPLES[dig];
            vector<string> tmp;
            for (auto& r : res)
                for (auto s : samp)
                    tmp.push_back(r + s);
            res = move(tmp);
        }
        return res;
    }
};

int main() {
    return 0;
}
