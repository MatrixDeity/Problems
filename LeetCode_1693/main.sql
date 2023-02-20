/**
    LeetCode_1693
    https://leetcode.com/problems/daily-leads-and-partners/
    MatrixDeity, 2023.
*/

select
    date_id,
    make_name,
    count(distinct lead_id) as 'unique_leads',
    count(distinct partner_id) as 'unique_partners'
from DailySales
group by
    date_id,
    make_name
