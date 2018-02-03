/**
    LeetCode_760
    https://leetcode.com/problems/find-anagram-mappings/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res;
        int n = (int) A.size();
        res.reserve(n);
        unordered_map<int, int> um;
        for (int i = 0; i < n; ++i) {
            um[B[i]] = i;
        }
        for (auto item : A) {
            res.push_back(um[item]);
        }
        return res;
    }
};

int main() {
    return 0;
}
