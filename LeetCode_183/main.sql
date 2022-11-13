/**
    LeetCode_183
    https://leetcode.com/problems/customers-who-never-order/
    MatrixDeity, 2022.
*/

select Name "Customers" from Customers where id not in (select CustomerId from Orders);
