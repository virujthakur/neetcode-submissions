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
    int ans = INT_MIN;
    int recur(TreeNode* root){
        if(root == nullptr) return 0;
        int left = recur(root->left);
        int right = recur(root->right);
        ans = max(ans, left+ right+ root->val);
        return max(0, max(left, right)+ root->val);

    }
    int maxPathSum(TreeNode* root) {
        recur(root);
        return ans;
    }
};
