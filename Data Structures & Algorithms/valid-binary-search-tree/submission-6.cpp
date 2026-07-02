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
    bool dfs(TreeNode* root, int greater, int lower) {
        if (!root) return true;

        greater = max(greater, root->val);
        lower = min(lower, root->val);

        if (root->val >= greater || root->val <= lower) return false;

        return dfs(root->left, root->val, lower) && dfs(root->right, greater, root->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MAX, INT_MIN);
    }
};
