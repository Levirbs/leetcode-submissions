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
        vector<int> res;
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

            res.push_back(levelVal[0]);
        }
        return res;
    }
};
