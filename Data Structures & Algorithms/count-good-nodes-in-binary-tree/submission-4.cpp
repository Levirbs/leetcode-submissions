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
    int dfs(TreeNode* root, int max) {
        if (!root) return 0;

        int i = 0;

        if (root->val >= max) {
            max = root->val;
            i = 1;
        }

        return i + dfs(root->left, max) + dfs(root->right, max);
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
