/**
    LeetCode_113
    https://leetcode.com/problems/path-sum-ii/description/
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        function<void(TreeNode*, int sum)> impl = [&impl, &res, &tmp] (TreeNode* root, int sum) {
            if (root == nullptr)
                return;

            tmp.push_back(root->val);
            if (root->left == nullptr && root->right == nullptr && sum == root->val)
                res.push_back(tmp);
            impl(root->left, sum - root->val);
            impl(root->right, sum - root->val);
            tmp.pop_back();
        };
        impl(root, sum);
        return res;
    }
};

int main() {
    return 0;
}
