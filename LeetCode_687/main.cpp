/**
    LeetCode_687
    https://leetcode.com/problems/longest-univalue-path/description/
    MatrixDeity, 2017.
*/

#include <iostream>
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
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        function<int(TreeNode*)> impl = [&impl, &res] (TreeNode* root) {
            if (root == nullptr)
                return 0;

            int lLen = root->left != nullptr ? impl(root->left) : 0;
            int rLen = root->right != nullptr ? impl(root->right) : 0;
            int lRes = root->left != nullptr && root->val == root->left->val ? lLen + 1 : 0;
            int rRes = root->right != nullptr && root->val == root->rigth->val ? rLen + 1 : 0;
            res = max(lRes + rRes, res);
            return max(lRes, rRes);
        };
        return res;
    }
};

int main() {
    return 0;
}
