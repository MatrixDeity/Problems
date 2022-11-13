/**
    LeetCode_620
    https://leetcode.com/problems/not-boring-movies/
    MatrixDeity, 2022.
*/

select * from Cinema where id % 2 = 1 and description <> "boring" order by rating desc;
