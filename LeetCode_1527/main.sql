/**
    LeetCode_1527
    https://leetcode.com/problems/patients-with-a-condition/
    MatrixDeity, 2023.
*/

select patient_id, patient_name, conditions from Patients where conditions like 'DIAB1%' or conditions like '% DIAB1%';
