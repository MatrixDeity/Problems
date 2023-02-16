/**
    LeetCode_196
    https://leetcode.com/problems/delete-duplicate-emails/
    MatrixDeity, 2023.
*/

delete p1 from Person p1, Person p2 where p1.email = p2.email and p2.id < p1.id;
