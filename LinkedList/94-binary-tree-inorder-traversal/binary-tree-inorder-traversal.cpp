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
vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return ans;
       // L N R
       //jab tak left ja skte ho, left jao. put all nodes in a stack. jese hi nahi, ja skte, put that node in ans, and uska right bhi stack me daal do.
       TreeNode* temp = root;
       stack<TreeNode*>st;
    //    st.push(root);
       while(temp || !st.empty()){
            while(temp){
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            // st.pop();
            temp = temp->right;
        }
        return ans;
    }
};