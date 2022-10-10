/**
    LeetCode_1448
    https://leetcode.com/problems/count-good-nodes-in-binary-tree/
    MatrixDeity, 2022.
*/

#include <algorithm>
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
    int goodNodes(TreeNode* root) {
        int maxVal = -9999999;
        int res = 0;

        function<void(TreeNode*, int)> impl = [&impl, &res] (TreeNode* node, int maxVal) {
            if (node == nullptr) {
                return;
            }

            if (node->val >= maxVal) {
                maxVal = node->val;
                ++res;
            }

            impl(node->left, maxVal);
            impl(node->right, maxVal);
        };

        impl(root, maxVal);
        return res;
    }
};
