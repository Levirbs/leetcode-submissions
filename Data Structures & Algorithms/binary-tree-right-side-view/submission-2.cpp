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
        vector<int> res;

        fila.push(root);

        while (!fila.empty()) {
            int levelSize = fila.size();
            vector<int> levelVal;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* el = fila.front();

                if(el->right) fila.push(el->right);
                if(el->left) fila.push(el->left);

                fila.pop();
                levelVal.push_back(el->val);
            }

            res.push_back(levelVal[0]);
        }

        return res;
    }
};
