/**
    LeetCode_543
    https://leetcode.com/problems/diameter-of-binary-tree/description/
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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        function<int(TreeNode*)> impl = [&impl] (TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }
            return max(impl(root->left), impl(root->right)) + 1;
        };
        int res = impl(root->left) + impl(root->right);
        int child = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return max(child, res);
    }
};

int main() {
    return 0;
}
