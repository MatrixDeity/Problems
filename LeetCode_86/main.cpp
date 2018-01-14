/**
    LeetCode_86
    https://leetcode.com/problems/partition-list/description/
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
    ListNode* partition(ListNode* head, int x) {
        ListNode base1(0), base2(0), *ptr1 = &base1, *ptr2 = &base2;
        while (head != nullptr) {
            if (head->val < x) {
                ptr1->next = head;
                ptr1 = ptr1->next;
            } else {
                ptr2->next = head;
                ptr2 = ptr2->next;
            }
            head = head->next;
        }
        ptr1->next = base2.next;
        ptr2->next = nullptr;
        return base1.next;
    }
};

int main() {
    return 0;
}
