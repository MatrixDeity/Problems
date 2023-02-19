/**
    LeetCode_1741
    https://leetcode.com/problems/find-total-time-spent-by-each-employee/
    MatrixDeity, 2023.
*/

select
    event_day as 'day',
    emp_id,
    sum(out_time - in_time) as 'total_time'
from Employees
group by
    event_day,
    emp_id
