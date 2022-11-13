/**
    LeetCode_511
    https://leetcode.com/problems/game-play-analysis-i/
    MatrixDeity, 2022.
*/

select player_id, min(event_date) "first_login" from Activity group by player_id;
