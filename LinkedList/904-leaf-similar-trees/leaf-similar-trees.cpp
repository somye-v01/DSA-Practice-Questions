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

    // void inorder1(TreeNode* root1,vector<int>& v1 ){
    //     if (root1 == nullptr) {
    //         return;
    //     }
    //     if(root1->left==nullptr && root1->right==nullptr){ 
    //         v1.push_back(root1->val);
    //         return;
    //     }
    //     inorder1(root1->left,v1);
    //     inorder1(root1->right,v1);
    // }

    void inorder2(TreeNode* root2,vector<int>& v2 ){
        if (root2 == nullptr) {
            return;
        }
        if(root2->left==nullptr && root2->right==nullptr){ 
            v2.push_back(root2->val);
            return;
        }
        inorder2(root2->left,v2);
        inorder2(root2->right,v2);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        inorder2(root1,v1);
        inorder2(root2,v2);
        return v1==v2;
    }
};