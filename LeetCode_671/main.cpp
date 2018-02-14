/**
    LeetCode_671
    https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <functional>
#include <climits>

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
    int findSecondMinimumValue(TreeNode* root) {
        int fir = INT_MAX, sec = INT_MAX;
        function<void(TreeNode*)> impl = [&impl, &fir, &sec] (TreeNode* root) {
            if (root == nullptr)
                return;

            if (root->val < fir) {
                swap(fir, sec);
                fir = root->val;
            } else if (root->val != fir && root->val < sec) {
                sec = root->val;
            }
            impl(root->left);
            impl(root->right);
        };
        impl(root);
        return sec != INT_MAX ? sec : -1;
    }
};

int main() {
    return 0;
}
