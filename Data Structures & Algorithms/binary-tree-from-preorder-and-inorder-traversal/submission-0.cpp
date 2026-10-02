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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int l, int h, int& pre_idx){
        if(l>h) return nullptr;
        int rootVal = preorder[pre_idx++];
        if(l==h){
            return new TreeNode(rootVal);
        }
        int mid = -1;
        for(int k=l; k<=h; k++){
            if(inorder[k] == rootVal){
                mid = k;
                break;
            }
        }
        TreeNode* left = solve(preorder, inorder, l, mid-1, pre_idx);
        TreeNode* right = solve(preorder, inorder, mid+1, h, pre_idx);
        TreeNode* root = new TreeNode(rootVal);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder first element = root
        // inorder -> root->left saara left child
        // do this recursively
        int pre_idx = 0;
        return solve(preorder, inorder, 0, preorder.size()-1, pre_idx);
    }
};
