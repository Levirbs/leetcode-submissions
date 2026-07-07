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
        if (!root) return {};

        queue<TreeNode*> fila;

        fila.push(root);

        vector<vector<int>> res;

        while (!fila.empty()) {
            int levelSize = fila.size();

            vector<int> levelVal;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = fila.front();
                fila.pop();

                if (node->left) fila.push(node->left);
                if (node->right) fila.push(node->right);

                levelVal.push_back(node->val);
            }
            res.push_back(levelVal);
        }

        return res;
    }
};
