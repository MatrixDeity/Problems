/**
    LeetCode_1050
    https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/
    MatrixDeity, 2023.
*/

select
    actor_id,
    director_id
from ActorDirector
group by
    actor_id,
    director_id
having count(*) >= 3
