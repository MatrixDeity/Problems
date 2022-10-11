/**
    LeetCode_1328
    https://leetcode.com/problems/break-a-palindrome/
    MatrixDeity, 2022.
*/

#include <string>

using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        const size_t N = palindrome.size();
        if (N < 2) {
            return "";
        }

        for (size_t i = 0; i < N/2; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        palindrome[N - 1] = 'b';
        return palindrome;
    }
};
