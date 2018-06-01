/**
    LeetCode_108
    https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
    MatrixDeity, 2018.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        function<TreeNode*(int, int)> build = [&build, &nums] (int beg, int end) -> TreeNode* {
            if (beg >= end) {
                return nullptr;
            }

            int mid = beg + (end - beg) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = build(beg, mid);
            root->right = build(mid + 1, end);
            return root;
        };
        return build(0, nums.size());
    }
};

int main() {
    return 0;
}
