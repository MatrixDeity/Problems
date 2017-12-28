/**
    LeetCode_199
    https://leetcode.com/problems/binary-tree-right-side-view/description/
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        function<void(TreeNode*, int)> impl = [&] (TreeNode* root, int n) {
            if (root == nullptr)
                return;

            if (res.size() == n)
                res.push_back(root->val);
            impl(root->right, n + 1);
            impl(root->left, n + 1);
        };
        impl(root, 0);
        return res;
    }
};

int main() {
    return 0;
}
