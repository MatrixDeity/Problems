/**
    LeetCode_1729
    https://leetcode.com/problems/find-followers-count/
    MatrixDeity, 2023.
*/

select
    user_id,
    count(distinct follower_id) as 'followers_count'
from Followers
group by user_id
order by user_id
