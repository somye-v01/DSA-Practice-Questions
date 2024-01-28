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

    int solve(TreeNode* root,unordered_map<TreeNode*,int>&m){
        if(!root) return 0;
        if(m.find(root)!=m.end()) return m[root];
        int rob = 0;
        //include
        int temp = root->val;
        rob+=temp;
        if(root->left){
            rob+=  solve(root->left->left,m) + solve(root->left->right,m);
        }
         if(root->right){
           rob += solve(root->right->left,m) + solve(root->right->right,m);
        }
        // rob = temp1+temp2;
        //exclude
        int notrob = 0;
        int temp11 = 0;
        int temp22 = 0;
        if(root->left){
            temp11 = + solve(root->left,m);
        }
         if(root->right){
            temp22= solve(root->right,m);
        }
        notrob = temp11+temp22;
        m[root]= max(rob,notrob);
        return m[root];
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>m;
        return solve(root,m);
    }
};