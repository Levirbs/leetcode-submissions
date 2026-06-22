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
    int dfs(TreeNode* node, int greater) {
        if (!node) return 0;

        int res = 0;

        if (node->val >= greater) {
            greater = node->val;
            res = 1;
        }

        return res + dfs(node->left, greater) + dfs(node->right, greater);
    }

public:
    int goodNodes(TreeNode* root) {   
        return dfs(root, root->val);
    }
};
