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
private:
    bool dfs(TreeNode* node, int greater, int lower) {
        if (!node) return true;

        greater = max(greater, node->val);
        lower = min(lower, node->val);

        if (node->val <= lower || node->val >= greater) return false;

        return dfs(node->left, node->val, lower) && dfs(node->right, greater, node->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MAX, INT_MIN);
    }
};
