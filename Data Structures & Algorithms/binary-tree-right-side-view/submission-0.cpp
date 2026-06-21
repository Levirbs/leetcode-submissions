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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> bfs;
        
        queue<TreeNode*> fila;
        fila.push(root);

        while (!fila.empty()) {
            int levelSize = fila.size();
            vector<int> levelVal;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = fila.front();

                if (node->right) fila.push(node->right);
                if (node->left) fila.push(node->left);

                levelVal.push_back(node->val);

                fila.pop();
            }

            bfs.push_back(levelVal);
        }

        vector<int> res;
        for (const auto& level : bfs) {
            res.push_back(level[0]);
        }

        return res;
    }
};
