/**
    LeetCode_623
    https://leetcode.com/problems/add-one-row-to-tree/
    MatrixDeity, 2022.
*/

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        }

        function<void(TreeNode*, int)> impl = [&impl, &val] (TreeNode* node, int depth) {
            if (node == nullptr) {
                return;
            }

            if (depth == 2) {
                node->left = new TreeNode(val, node->left, nullptr);
                node->right = new TreeNode(val, nullptr, node->right);
                return;
            }

            impl(node->left, depth - 1);
            impl(node->right, depth - 1);
        };

        impl(root, depth);
        return root;
    }
};
