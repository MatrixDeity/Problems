/**
    LeetCode_176
    https://leetcode.com/problems/second-highest-salary/
    MatrixDeity, 2023.
*/

select (select distinct salary from Employee order by salary desc limit 1 offset 1) as 'SecondHighestSalary';
