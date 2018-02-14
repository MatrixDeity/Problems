/**
    LeetCode_404
    https://leetcode.com/problems/sum-of-left-leaves/description/
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
private:
    int sum = 0;

public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
            return sum;

        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            sum += root->left->val;
        }
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return sum;
    }
};

int main() {
    return 0;
}
