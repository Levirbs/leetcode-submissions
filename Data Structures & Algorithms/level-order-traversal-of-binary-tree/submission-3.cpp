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

        vector<vector<int>> res;
        vector<TreeNode*> currentLevel = {root};
        vector<TreeNode*> nextLevel;

        while (!currentLevel.empty()) {
            vector<int> levelVal;

            for (const TreeNode* node : currentLevel) {
                levelVal.push_back(node->val);

                if (node->left) nextLevel.push_back(node->left);
                if (node->right) nextLevel.push_back(node->right);
            }
            
            res.push_back(levelVal);
            
            swap(currentLevel, nextLevel); 
            
            nextLevel.clear();
        }
        
        return res;
    }
};