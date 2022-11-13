/**
    LeetCode_175
    https://leetcode.com/problems/combine-two-tables/
    MatrixDeity, 2022.
*/

select FirstName, LastName, City, State from Person left join Address on Person.PersonId = Address.PersonId;
