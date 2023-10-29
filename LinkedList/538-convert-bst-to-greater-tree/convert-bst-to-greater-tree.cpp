class Solution {
public:
    vector<int> ans;

    void inorderstore(TreeNode* root){ //already sorted
        if(!root) return;
        inorderstore(root->left);
        ans.push_back(root->val);
        inorderstore(root->right);
    }
     void inordertraverse(TreeNode* root){ //already sorted
        if(!root) return;
        inordertraverse(root->left);
        // ans.push_back(root->val);
        int temp = root->val;
        int sum = 0;
        for(int i = 0; i < ans.size();i++){
            if(ans[i]>temp){
                sum+=ans[i];
            }
        }
        root->val = root->val+sum;
        inordertraverse(root->right);
    }

    TreeNode* convertBST(TreeNode* root) {
        //traverse -> sorted vector me store krlunga
       inorderstore(root);
        for(auto x : ans){
            cout<<x<<" ";
        }
        inordertraverse(root);
        return root;
    }
};