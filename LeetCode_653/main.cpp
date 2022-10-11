/**
    LeetCode_653
    https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
    MatrixDeity, 2022.
*/

#include <vector>
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;

        function<void(TreeNode*)> dfs = [&dfs, &vec] (TreeNode* node) {
            if (node == nullptr) {
                return;
            }

            dfs(node->left);
            vec.push_back(node->val);
            dfs(node->right);
        };

        dfs(root);

        int i = 0, j = vec.size() - 1;
        while (i < j) {
            int sum = vec[i] + vec[j];

            if (sum == k) {
                return true;
            }
            if (sum < k) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
    }
};
