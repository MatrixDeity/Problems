/**
    LeetCode_1084
    https://leetcode.com/problems/sales-analysis-iii/
    MatrixDeity, 2023.
*/

select
    p.product_id,
    product_name
from Product as p
left join Sales as s
on p.product_id = s.product_id
group by s.product_id
having
    min(sale_date) >= "2019-01-01"
    and max(sale_date) <= "2019-03-31"
