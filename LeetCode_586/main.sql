/**
    LeetCode_586
    https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/
    MatrixDeity, 2023.
*/

select customer_number
from Orders
group by customer_number
order by count(customer_number) desc
limit 1
