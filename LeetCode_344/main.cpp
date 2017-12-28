/**
    LeetCode_344
    https://leetcode.com/problems/reverse-string/description/
    MatrisDeity, 2017.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        string res = s;
        int i = 0, j = (int) s.size() - 1;
        while (i < j) {
            swap(res[i++], res[j--]);
        }
        return res;
    }
};

int main() {
    return 0;
}
