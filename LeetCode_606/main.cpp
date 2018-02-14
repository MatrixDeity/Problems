/**
    LeetCode_606
    https://leetcode.com/problems/construct-string-from-binary-tree/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>

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
    string tree2str(TreeNode* t) {
        string res = "";
        if (t == nullptr)
            return res;

        res += to_string(t->val);
        if (t->left != nullptr) {
            res += "(" + tree2str(t->left) + ")";
        }
        if (t->right != nullptr) {
            res += t->left == nullptr ? "()" : "";
            res += "(" + tree2str(t->right) + ")";
        }
        return res;
    }
};

int main() {
    return 0;
}
