/**
    LeetCode_637
    https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <queue>

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root == nullptr)
            return res;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            double sum = 0.0;
            size_t n = q.size();
            for (size_t i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
                sum += node->val;
            }
            res.push_back(sum / n);
        }
        return res;
    }
};

int main() {
    return 0;
}
