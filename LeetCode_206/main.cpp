/**
    LeetCode_206
    https://leetcode.com/problems/reverse-linked-list/description/
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
    ListNode* reverseList(ListNode* head) {
        ListNode base(0);
        auto ptr = head;
        while (ptr != nullptr) {
            auto tail = ptr->next;
            ptr->next = base.next;
            base.next = ptr;
            ptr = tail;
        }
        return base.next;
    }
};

int main() {
    return 0;
}
