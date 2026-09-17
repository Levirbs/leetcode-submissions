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

        queue<TreeNode*> fila;

        fila.push(root);

        vector<int> res;

        while (!fila.empty()) {
            TreeNode* first = fila.front();
            res.push_back(first->val);

            int levelLen = fila.size();
            for(int i = 0; i < levelLen; i++) {
                TreeNode* node = fila.front();

                if (node->right) fila.push(node->right);
                if (node->left) fila.push(node->left);

                fila.pop();
            }
        }

        return res;
    }
};
