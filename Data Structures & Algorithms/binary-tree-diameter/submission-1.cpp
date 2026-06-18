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
    int maxDepth(TreeNode* root, int &res) {
        if (!root) return 0;

        int l = maxDepth(root->left, res);
        int r = maxDepth(root->right, res);

        res = max(res, l + r);

        return max(l, r) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diamater = 0;
        maxDepth(root, diamater);
        return diamater;
    }
};
