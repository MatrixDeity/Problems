/**
    LeetCode_584
    https://leetcode.com/problems/find-customer-referee/
    MatrixDeity, 2023.
*/

select name from Customer where referee_id is null or referee_id <> 2;
