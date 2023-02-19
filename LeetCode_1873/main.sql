/**
    LeetCode_1873
    https://leetcode.com/problems/calculate-special-bonus/
    MatrixDeity, 2023.
*/

select employee_id,
    case when employee_id % 2 = 1 and name not like 'M%' then salary
    else 0
end 'bonus'
from Employees order by employee_id;
