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

    void solve(TreeNode* root, int lev, vector<int>& temp){
        if(!root) return;
        if(lev == temp.size()){
            temp.push_back(root->val);
        }
        if(root->right){
            solve(root->right,lev+1,temp);
        }
        if(root->left){
            solve(root->left,lev+1,temp);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        // N R L
        vector<int> temp;
        solve(root,0,temp);
        return temp;
    }
};