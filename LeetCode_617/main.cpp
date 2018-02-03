/**
    LeetCode_617
    https://leetcode.com/problems/merge-two-binary-trees/description/
    MatrixDeity, 2018.
*/

#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr || t2 == nullptr)
            return t1 == nullptr ? t2 : t1;

        auto tmp = new TreeNode(t1->val + t2->val);
        tmp->left = mergeTrees(t1->left, t2->left);
        tmp->right = mergeTrees(t1->right, t2->right);
        return tmp;
    }
};

int main() {
    return 0;
}
