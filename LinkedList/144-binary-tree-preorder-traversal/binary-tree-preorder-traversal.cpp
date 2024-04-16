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
vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return ans;
       // N L R
       TreeNode* temp = root;
       stack<TreeNode*>st;
       st.push(temp);
       while(!st.empty()){
        TreeNode* curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        if(curr->right){
            st.push(curr->right);
        }
        if(curr->left){
            st.push(curr->left);
        }
        
        // st.push(temp->left);
        // temp = st.top();
        // temp = temp->right;
        // }
       }
        return ans;
    }
    
};