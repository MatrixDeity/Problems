/**
    LeetCode_24
    https://leetcode.com/problems/swap-nodes-in-pairs/description/
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
    ListNode* swapPairs(ListNode* head) {
        ListNode base(0);
        base.next = head;
        ListNode* ptr = &base;
        while (ptr->next != nullptr && ptr->next->next != nullptr) {
            ListNode* f = ptr->next;
            ListNode* s = ptr->next->next;
            f->next = s->next;
            ptr->next = s;
            ptr->next->next = f;
            ptr = ptr->next->next;
        }
        return base.next;
    }
};

int main() {
    return 0;
}
