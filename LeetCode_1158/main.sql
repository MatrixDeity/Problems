/**
    LeetCode_1158
    https://leetcode.com/problems/market-analysis-i/
    MatrixDeity, 2023.
*/

select
    user_id as buyer_id,
    join_date,
    ifnull(count(order_id), 0) as orders_in_2019
from Users
left join Orders
on user_id = buyer_id and year(order_date) = '2019'
group by user_id
