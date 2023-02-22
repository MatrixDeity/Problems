/**
    LeetCode_1393
    https://leetcode.com/problems/capital-gainloss/
    MatrixDeity, 2023.
*/

select
    tmp.stock_name,
    sum(tmp.price) as capital_gain_loss
from (
    select
        stock_name,
        case
            when operation = 'Buy' then -price
            when operation = 'Sell' then price
        end as price
    from Stocks
) as tmp
group by tmp.stock_name
