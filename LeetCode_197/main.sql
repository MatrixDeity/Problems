/**
    LeetCode_197
    https://leetcode.com/problems/rising-temperature/
    MatrixDeity, 2022.
*/

select w1.Id from Weather w1, Weather w2 where DATEDIFF(w1.RecordDate, w2.RecordDate) = 1 and w1.Temperature > w2.Temperature
