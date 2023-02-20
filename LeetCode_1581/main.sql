/**
    LeetCode_1581
    https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/
    MatrixDeity, 2023.
*/

select
    customer_id,
    count(visit_id) as 'count_no_trans'
from Visits
where
    visit_id not in (
        select distinct visit_id from Transactions
    )
group by customer_id
