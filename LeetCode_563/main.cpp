/**
    LeetCode_563
    https://leetcode.com/problems/binary-tree-tilt/description/
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
    int findTilt(TreeNode* root) {
        int res = 0;
        function<int(TreeNode*)> impl = [&impl, &res] (TreeNode* root) {
            if (root == nullptr)
                return 0;

            int l = impl(root->left);
            int r = impl(root->right);
            res += abs(l - r);
            return l + r + root->val;
        };
        impl(root);
        return res;
    }
};

int main() {
    return 0;
}
