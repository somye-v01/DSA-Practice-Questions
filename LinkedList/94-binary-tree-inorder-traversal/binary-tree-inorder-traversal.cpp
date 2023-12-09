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
    void inorderTraversalHelper(TreeNode* root,vector<int>& ans){
        if(root == nullptr){
                return ;
            }
            //INORDER - L,N,R
            
            inorderTraversalHelper(root->left,ans); //Left
            ans.push_back(root->val);
            inorderTraversalHelper(root->right,ans);
            
        }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderTraversalHelper(root,ans);
        return ans;
    }
};