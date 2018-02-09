/**
    LeetCode_744
    https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
    MatrixDeity, 2018.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char c : letters) {
            if (c > target)
                return c;
        }
        return letters[0];
    }
};

int main() {
    return 0;
}
