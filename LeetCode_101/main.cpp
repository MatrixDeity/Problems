/**
    LeetCode_101
    https://leetcode.com/problems/symmetric-tree/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <functional>

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        function<bool(TreeNode*, TreeNode*)> impl = [&impl] (TreeNode* r1, TreeNode* r2) {
            if (r1 == nullptr && r2 == nullptr)
                return true;
            if (r1 == nullptr || r2 == nullptr)
                return false;
            return r1->val == r2->val && impl(r1->left, r2->right) && impl(r1->right, r2->left);
        };
        return impl(root->left, root->right);
    }
};

int main() {
    return 0;
}
