/**
    LeetCode_124
    https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
    MatrixDeity, 2017.
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
    int maxPathSum(TreeNode* root) {
        int ans = -0x7FFFFFFF;
        function<int(TreeNode*)> impl = [&impl, &ans] (TreeNode* root) {
            if (root == nullptr)
                return 0;

            int leftSum = max(impl(root->left), 0);
            int rightSum = max(impl(root->right), 0);
            int pathSum = root->val + leftSum + rightSum;
            ans = max(pathSum, ans);
            return root->val + max(leftSum, rightSum);
        };
        impl(root);
        return ans;
    }
};

int main() {
    return 0;
}
