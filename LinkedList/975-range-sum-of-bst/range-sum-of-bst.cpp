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
// vector<int>v;
int inorder(TreeNode* root,int low, int high){
    if(!root) return 0;
    int sum = 0;
    
    sum+=inorder(root->left, low,  high);
    if(root->val >= low && root->val <= high){
        sum+=root->val;
    }
    sum+=inorder(root->right, low,  high);
    return sum;
    
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = inorder(root,low,high);
        return ans;
    }
};