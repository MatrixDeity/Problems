/**
    LeetCode_94
    https://leetcode.com/problems/binary-tree-inorder-traversal/
    MatrixDeity, 2022.
*/

#include <vector>
#include <functional>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        function<void(TreeNode*)> impl = [&impl, &res] (TreeNode* node) {
            if (node == nullptr) {
                return;
            }

            impl(node->left);
            res.push_back(node->val);
            impl(node->right);
        };

        impl(root);
        return res;
    }
};
