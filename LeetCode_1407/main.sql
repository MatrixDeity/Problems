/**
    LeetCode_1407
    https://leetcode.com/problems/top-travellers/
    MatrixDeity, 2023.
*/

select
    u.name,
    ifnull(sum(r.distance), 0) as 'travelled_distance'
from Users as u
left join Rides as r on u.id = r.user_id
group by u.id
order by
    travelled_distance desc,
    u.name asc