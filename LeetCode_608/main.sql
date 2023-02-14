/**
    LeetCode_608
    https://leetcode.com/problems/tree-node/
    MatrixDeity, 2023.
*/

select id, case
    when p_id is null then 'Root'
    when p_id in (select id from Tree) and id in (select p_id from Tree) then 'Inner'
    else 'Leaf'
end
as 'type' from Tree;
