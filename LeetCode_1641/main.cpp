/**
    LeetCode_1641
    https://leetcode.com/problems/count-sorted-vowel-strings/
    MatrixDeity, 2022.
*/

#include <vector>

using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        // C ^(n) _(n + 5 - 1) = (n + 4)! / (n! * (n + 5 - 1 - n)!) =
        // = (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24

        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};
