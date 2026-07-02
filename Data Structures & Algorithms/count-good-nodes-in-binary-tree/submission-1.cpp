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
    int dfs(TreeNode* root, int greater) {
        if (!root) return 0;

        int i = 0;
        if (root->val >= greater) {
            i = 1;
            greater = root->val;
        }

        return i + dfs(root->left, greater) + dfs(root->right, greater); 
    }

public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
