/**
    LeetCode_19
    https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head, *p2 = head, *prev = nullptr;
        for (int i = 0; i < n; ++i)
            p2 = p2->next;
        if (p2 == nullptr)
            return head->next;
        while (p2 != nullptr) {
            prev = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        prev->next = p1->next;
        return head;
    }
};

int main() {
    return 0;
}
