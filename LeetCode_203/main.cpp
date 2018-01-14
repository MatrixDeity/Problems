/**
    LeetCode_203
    https://leetcode.com/problems/remove-linked-list-elements/description/
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode base(0);
        base.next = head;
        auto ptr = &base;
        while (ptr->next != nullptr) {
            if (ptr->next->val == val)
                ptr->next = ptr->next->next;
            else
                ptr = ptr->next;
        }
        return base.next;
    }
};

int main() {
    return 0;
}
