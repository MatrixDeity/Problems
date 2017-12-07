/**
    LeetCode_21
    https://leetcode.com/problems/merge-two-sorted-lists/description/
    MatrixDeity, 2017.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode base(0);
        ListNode* ptr = &base;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            } else {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        ptr->next = (l1 != nullptr ? l1 : l2);
        return base.next;
    }
};

int main() {
    return 0;
}
