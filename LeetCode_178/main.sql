/**
    LeetCode_178
    https://leetcode.com/problems/rank-scores/
    MatrixDeity, 2023.
*/

select
    score,
    (
        select count(distinct score)
        from Scores as s2
        where s2.score >= s1.score
    ) as 'rank'
from Scores as s1
order by score desc
