/**
    LeetCode_257
    https://leetcode.com/problems/binary-tree-paths/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr)
            return res;
        function<void(TreeNode*, string)> impl = [&impl, &res] (TreeNode* root, string cur) {
            if (root->left == nullptr && root->right == nullptr) {
                res.push_back(cur);
            }
            if (root->left != nullptr)
                impl(root->left, cur + "->" + to_string(root->left->val));
            if (root->right != nullptr)
                impl(root->right, cur + "->" + to_string(root->right->val));
        };
        impl(root, to_string(root->val));
        return res;
    }
};

int main() {
    return 0;
}
