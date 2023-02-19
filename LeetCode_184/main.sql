/**
    LeetCode_184
    https://leetcode.com/problems/department-highest-salary/
    MatrixDeity, 2023.
*/

select
    d.name as 'Department',
    e.name as 'Employee',
    salary as 'Salary'
from Employee as e
join Department as d
on e.departmentId = d.id
where (departmentId, salary) in (
    select
        departmentId,
        max(salary)
    from Employee
    group by departmentId
)
