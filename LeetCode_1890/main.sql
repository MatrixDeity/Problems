/**
    LeetCode_1890
    https://leetcode.com/problems/the-latest-login-in-2020/
    MatrixDeity, 2023.
*/

select
    user_id,
    max(time_stamp) as 'last_stamp'
from Logins
where year(time_stamp) = '2020'
group by user_id
