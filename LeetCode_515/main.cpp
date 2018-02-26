/**
    LeetCode_515
    https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
    MatrixDeity, 2018.
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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size(), r = INT_MIN;
            while (n-- > 0) {
                auto a = q.front();
                r = max(a->val, r);
                if (a->left != nullptr)
                    q.push(a->left);
                if (a->right != nullptr)
                    q.push(a->right);
                q.pop();
            }
            res.push_back(r);
        }
        return res;
    }
};

int main() {
    return 0;
}
