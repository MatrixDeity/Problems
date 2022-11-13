/**
    LeetCode_182
    https://leetcode.com/problems/duplicate-emails/
    MatrixDeity, 2022.
*/

select Email from Person group by Email having count(Email) > 1;
