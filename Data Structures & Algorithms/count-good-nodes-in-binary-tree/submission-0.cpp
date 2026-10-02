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
    int dfs(TreeNode* root, int mx){
        if(root== nullptr) return 0;
        int left= dfs(root->left, max(root->val, mx));
        int right = dfs(root->right, max(root->val, mx));
        // cout<<left<<" "<<right<<" "<<root->val<<endl;
        return left+ right + (root->val >= mx);
    }
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        return dfs(root, -101);
    }
};
