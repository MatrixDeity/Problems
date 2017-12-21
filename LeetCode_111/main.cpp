/**
    LeetCode_111
    https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
    MatrixDeity, 2017.
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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr)
            return minDepth(root->right);
        if (root->right == nullptr)
            return minDepth(root->left);
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

int main() {
    return 0;
}
