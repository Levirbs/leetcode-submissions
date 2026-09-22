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
    unordered_map<int, int> mapaIN;
    int idxpre = 0;

    TreeNode* dfs(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;

        int val = preorder[idxpre++];
        TreeNode* newNode = new TreeNode(val);

        int mid = mapaIN[val];

        newNode->left = dfs(preorder, left, mid - 1);
        newNode->right = dfs(preorder, mid + 1, right);

        return newNode;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mapaIN[inorder[i]] = i;
        }
        return dfs(preorder, 0, n - 1);
    }
};
