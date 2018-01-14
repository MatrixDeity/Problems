/**
    LeetCode_2
    https://leetcode.com/problems/add-two-numbers/description/
    MatrixDeity, 2018.
*/

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode base(0);
        auto ptr = &base;
        int rem = 0;
        while (l1 != nullptr || l2 != nullptr || rem != 0) {
            int val = (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + rem;
            ptr->next = new ListNode(val % 10);
            rem = val / 10;
            ptr = ptr->next;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        return base.next;
    }
};

int main() {
    return 0;
}
