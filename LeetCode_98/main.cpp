/**
    LeetCode_98
    https://leetcode.com/problems/validate-binary-search-tree/description/
    MatrixDeity, 2017.
*/

#include <iostream>

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
    using ll = long long;

    static const ll MAX = 1LL << 33;

    bool isValidBST(TreeNode* root, ll maxVal = MAX, ll minVal = -MAX) {
        if (root == nullptr)
            return true;

        return root->val < maxVal &&
               root->val > minVal &&
               isValidBST(root->left, root->val, minVal) &&
               isValidBST(root->right, maxVal, root->val);
    }
};

int main() {
    return 0;
}
