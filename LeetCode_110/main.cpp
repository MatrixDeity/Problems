/**
    LeetCode_110
    https://leetcode.com/problems/balanced-binary-tree/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <functional>
#include <cmath>

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
    bool isBalanced(TreeNode* root) {
        function<int(TreeNode*)> impl = [&impl] (TreeNode* root) {
            if (root == nullptr)
                return 0;

            int l = impl(root->left);
            int r = impl(root->right);
            int res = l != -1 && r != -1 && abs(l - r) <= 1 ? max(l, r) + 1 : -1;
            return res;
        };
        return impl(root) != -1;
    }
};

int main() {
    return 0;
}
