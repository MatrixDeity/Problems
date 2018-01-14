/**
    LeetCode_204
    https://leetcode.com/problems/count-primes/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> sieve(n, true);
        sieve[0] = sieve[1] = false;
        for (int i = 0; i * i < n; ++i) {
            if (sieve[i]) {
                for (int j = i * i; j < n; j += i) {
                    sieve[j] = false;
                }
            }
        }
        return count(sieve.begin(), sieve.end(), true);
    }
};

int main() {
    return 0;
}
