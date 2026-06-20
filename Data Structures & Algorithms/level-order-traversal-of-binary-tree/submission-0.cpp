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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<vector<TreeNode*>> fila;

        if (!root) return {};

        fila.push({root});

        while (!fila.empty()) {
            vector<TreeNode*> level = fila.front();
            fila.pop();

            vector<int> levelVal;
            vector<TreeNode*> nextLevel;

            for (const TreeNode* node : level) {
                levelVal.push_back(node->val);

                if (node->left) nextLevel.push_back(node->left);
                if (node->right) nextLevel.push_back(node->right);
            }
            res.push_back(levelVal);
            if (!nextLevel.empty())fila.push(nextLevel);
        }
        
        return res;
    }
};
