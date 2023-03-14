/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int result = 0;
        dfs(root, 0, result);
        return result;
    }

private:
    void dfs(TreeNode* node, int currSum, int& result) {
        if (!node) return;

        currSum = currSum * 10 + node->val;
        if (!node->left && !node->right) {
            result += currSum;
            return;
        }

        dfs(node->left, currSum, result);
        dfs(node->right, currSum, result);
    }
};