/**
    LeetCode_783
    https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
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
    int minDiffInBST(TreeNode* root) {
        const int MAX = 0x7FFFFFFF;
        int res = MAX;
        function<void(TreeNode*, int, int)> impl = [&impl, &res] (TreeNode* root, int mx, int mn) {
            if (root == nullptr)
                return;

            int cur = min(abs(mx - root->val), abs(root->val - mn));
            res = min(cur, res);
            impl(root->left, root->val, mn);
            impl(root->right, mx, root->val);
        };
        impl(root, MAX, MAX);
        return res;
    }
};

int main() {
    return 0;
}
