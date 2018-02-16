/**
    LeetCode_572
    https://leetcode.com/problems/subtree-of-another-tree/description/
    MatrixDeity, 2018.
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr || t == nullptr)
            return s == t;
        function<bool(TreeNode*, TreeNode*)> impl = [&impl] (TreeNode* s, TreeNode* t) {
            if (s == nullptr || t == nullptr)
                return s == t;

            return s->val == t->val && impl(s->left, t->left) && impl(s->right, t->right);
        };
        return impl(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};

int main() {
    return 0;
}
