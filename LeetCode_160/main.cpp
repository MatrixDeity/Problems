/**
    LeetCode_160
    https://leetcode.com/problems/intersection-of-two-linked-lists/description/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p1 = headA, p2 = headB;
        while (p1 != p2) {
            p1 = p1 != nullptr ? p1->next : headB;
            p2 = p2 != nullptr ? p2->next : headA;
        }
        return p1;
    }
};

int main() {
    return 0;
}
