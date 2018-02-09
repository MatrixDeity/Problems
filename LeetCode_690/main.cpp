/**
    LeetCode_690
    https://leetcode.com/problems/employee-importance/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <functional>
#include <unordered_map>
#include <vector>

using namespace std;

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> um;
        for (auto empl : employees) {
            um[empl->id] = empl;
        }
        function<int(int)> impl = [&impl, &um] (int id) {
            int res = um[id]->importance;
            for (auto empl : um[id]->subordinates) {
                res += impl(empl);
            }
            return res;
        };
        return impl(id);
    }
};

int main() {
    return 0;
}
