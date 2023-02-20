/**
    LeetCode_1587
    https://leetcode.com/problems/bank-account-summary-ii/
    MatrixDeity, 2023.
*/

select
    name,
    sum(amount) as balance
from Users as u
left join Transactions as t
on u.account = t.account
group by u.account
having balance > 10000
