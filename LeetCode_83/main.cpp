/**
    LeetCode_83
    https://leetcode.com/problems/remove-duplicates-from-sorted-list/discuss/
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        while (ptr != nullptr) {
            while (ptr->next != nullptr && ptr->val == ptr->next->val) {
                ptr->next = ptr->next->next;
            }
            ptr = ptr->next;
        }
        return head;
    }
};

int main() {
    return 0;
}
