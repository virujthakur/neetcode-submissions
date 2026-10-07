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
    bool check(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr and subRoot == nullptr) return true;
        if(root == nullptr) return false;
        if(subRoot == nullptr) return false;

        if(root->val  != subRoot->val) return false;
        bool left = check(root->left, subRoot->left);
        bool right = check(root->right, subRoot->right);
        return left && right;
    }

    bool ans = false;
    void dfs(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr) return;
        if(check(root, subRoot)) ans= true;
        dfs(root->left, subRoot);
        dfs(root->right, subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // for every node with value equal to subRoot->value
        // check left
        // check right
        // if recursively everything is equal return true
        // otherwise false
        dfs(root, subRoot);
        return ans;
    }
};
