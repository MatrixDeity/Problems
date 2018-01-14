/**
    LeetCode_437
    https://leetcode.com/problems/path-sum-iii/description/
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
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return 0;

        function<int(TreeNode*, int)> impl = [&impl] (TreeNode* root, int sum) {
            if (root == nullptr)
                return 0;

            return (root->val == sum) + impl(root->left, sum - root->val) + impl(root->right, sum - root->val);
        };
        return impl(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};

int main() {
    return 0;
}
