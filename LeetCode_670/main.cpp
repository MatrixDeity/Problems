/**
    LeetCode_670
    https://leetcode.com/problems/maximum-swap/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        if (num < 12)
            return num;
        string str = to_string(num);
        unordered_map<char, size_t> um;
        for (size_t i = 0; i < str.size(); ++i) {
            um[str[i]] = i;
        }
        for (size_t i = 0; i < str.size(); ++i) {
            for (char dig = '9'; dig > str[i]; --dig) {
                if (um[dig] > i) {
                    swap(str[um[dig]], str[i]);
                    return stoi(str);
                }
            }
        }
        return stoi(str);
    }
};

int main() {
    return 0;
}
