/**
    LeetCode_595
    https://leetcode.com/problems/big-countries/
    MatrixDeity, 2022.
*/

select name, population, area from World where population >= 25000000 or area >= 3000000;
