/**
    LeetCode_142
    https://leetcode.com/problems/linked-list-cycle-ii/description/
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
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode *ptr1 = head, *ptr2 = head;
        while (ptr2 != nullptr && ptr2->next != nullptr) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            if (ptr1 == ptr2)
                break;
        }
        if (ptr2 == nullptr || ptr2->next == nullptr)
            return nullptr;
        ptr1 = head;
        while (ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};

int main() {
    return 0;
}
