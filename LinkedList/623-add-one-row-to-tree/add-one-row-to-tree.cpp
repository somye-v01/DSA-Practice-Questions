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

    TreeNode* dfs(TreeNode* root, int val, int d){
        if(!root) return nullptr;
        if(d == 2){
            TreeNode* left = root->left;
            TreeNode* right = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = left;
            root->right->right = right;
            return root;
        }
        root->left = dfs(root->left,val,d-1);
        root->right = dfs(root->right,val,d-1);
        return root;

    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* r = new TreeNode(val);
            r->left = root;
            return r;
        }


        return dfs(root,val,depth);
    }
};