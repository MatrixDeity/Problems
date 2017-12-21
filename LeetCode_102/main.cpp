/**
    LeetCode_102
    https://leetcode.com/problems/binary-tree-level-order-traversal/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        function<void(TreeNode*, int)> impl = [&impl, &res] (TreeNode* root, size_t n) {
            if (root == nullptr)
                return;
            if (n == res.size())
                res.push_back({});
            res[n].push_back(root->val);
            impl(root->left, n + 1);
            impl(root->right, n + 1);
        };
        impl(root, 0);
        return res;
    }
};

int main() {
    return 0;
}
