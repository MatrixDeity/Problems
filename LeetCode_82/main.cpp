/**
    LeetCode_82
    https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode base(0), *p = &base;
        while (head != nullptr) {
            int val = head->val;
            if (head->next == nullptr || head->next->val != val) {
                p->next = head;
                p = p->next;
            }
            while (head != nullptr && head->val == val)
                head = head->next;
        }
        p->next = nullptr;
        return base.next;
    }
};

int main() {
    return 0;
}
