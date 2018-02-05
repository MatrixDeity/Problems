/**
    LeetCode_412
    https://leetcode.com/problems/fizz-buzz/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 || i % 5 == 0) {
                string tmp = i % 3 == 0 ? "Fizz" : "";
                tmp.append(i % 5 == 0 ? "Buzz" : "");
                res.push_back(tmp);
            } else {
                res.push_back(to_string(i));
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
