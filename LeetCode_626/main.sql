/**
    LeetCode_626
    https://leetcode.com/problems/exchange-seats/
    MatrixDeity, 2023.
*/

select
    case
        when id % 2 = 1 and id not in (select count(*) from Seat) then id + 1
        when id % 2 = 0 then id - 1
        else id
    end as id,
    student
from Seat
order by id
