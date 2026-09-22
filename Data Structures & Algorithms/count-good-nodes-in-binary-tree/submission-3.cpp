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
    int dfs(TreeNode* root, int maxv) {
        if (!root) return 0;

        int i = 0;
        if (root->val >= maxv) {
            i++;
            maxv = root->val;
        }

        return i + dfs(root->left, maxv) + dfs(root->right, maxv);
    }

public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
