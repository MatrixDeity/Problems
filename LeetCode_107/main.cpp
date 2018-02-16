/**
    LeetCode_107
    https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        function<void(TreeNode*, int)> impl = [&impl, &res] (TreeNode* root, int lvl) {
            if (root == nullptr)
                return;
            if (res.size() == lvl)
                res.push_back({});
            res[lvl].push_back(root->val);
            impl(root->left, lvl + 1);
            impl(root->right, lvl + 1);
        };
        impl(root, 0);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    return 0;
}
