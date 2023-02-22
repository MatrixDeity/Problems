/**
    LeetCode_1148
    https://leetcode.com/problems/article-views-i/
    MatrixDeity, 2023.
*/

select distinct author_id as 'id' from Views where author_id = viewer_id order by author_id;
