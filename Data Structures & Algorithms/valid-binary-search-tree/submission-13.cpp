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
    bool dfs(TreeNode* root, int max, int min, bool& res) {
        if (!res) return false;
        if (!root) return true;

        if (root->val <= min || root->val >= max) {
            res = false;
            return false;
        }

        return dfs(root->left, root->val, min, res) && dfs(root->right, max, root->val, res);
    }
public:
    bool isValidBST(TreeNode* root) {
        bool res = true;
        dfs(root, INT_MAX, INT_MIN, res);
        return res;
    }
};
