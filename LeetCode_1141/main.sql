/**
    LeetCode_1141
    https://leetcode.com/problems/user-activity-for-the-past-30-days-i/
    MatrixDeity, 2023.
*/

select activity_date as 'day', count(distinct user_id) as 'active_users' from Activity
where datediff('2019-07-27', activity_date) < 30 and datediff('2019-07-27', activity_date) > 0
group by activity_date;
