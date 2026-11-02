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
    bool isSametree(TreeNode* r1, TreeNode* r2) {
        if (!r1 && !r2) return true;

        if ((!r1 || !r2) || (r1->val != r2->val)) return false;

        return isSametree(r1->left, r2->left) && isSametree(r1->right, r2->right);
    } 
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (isSametree(root, subRoot)) return true;

        bool left = root->left ? isSubtree(root->left, subRoot) : false;
        bool right = root->right ? isSubtree(root->right, subRoot) : false;


        return left || right;
    }
};
