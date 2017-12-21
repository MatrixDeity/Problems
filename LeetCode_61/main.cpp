/**
    LeetCode_61
    https://leetcode.com/problems/rotate-list/description/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return head;

        int len = 1;
        ListNode* ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
            ++len;
        }
        ptr->next = head;
        k %= len;
        for (int i = 0; i < len - k; ++i)
            ptr = ptr->next;
        head = ptr->next;
        ptr->next = nullptr;
        return head;
    }
};

int main() {
    return 0;
}
