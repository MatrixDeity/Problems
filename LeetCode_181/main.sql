/**
    LeetCode_181
    https://leetcode.com/problems/employees-earning-more-than-their-managers/
    MatrixDeity, 2022.
*/

select e1.Name "Employee" from Employee e1, Employee e2 where e1.ManagerId = e2.Id and e1.Salary > e2.Salary;
