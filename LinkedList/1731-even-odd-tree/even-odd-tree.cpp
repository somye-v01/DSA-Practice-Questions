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

    bool checkOddEven(vector<int>&arr, int i){
        if(i%2==0){
            if(arr.size()==1){
                if(arr[0]%2!=0) return true;
                return false;
            }
            for(int i = 1; i < arr.size(); i++){
                if(arr[i] <= arr[i-1] || arr[i]%2==0 || arr[i-1]%2==0){
                    return false;
                }
            }
            return true;
        }
        else{
             if(arr.size()==1){
                if(arr[0]%2==0) return true;
                return false;
            }
            for(int i = 1; i < arr.size(); i++){
               
                if(arr[i] >= arr[i-1] || arr[i]%2!=0 || arr[i-1]%2!=0){
                    return false;
                }
            }
            return true;
        }
        
    }

    bool isEvenOddTree(TreeNode* root) {
        //bfs code for tree
        queue<TreeNode*>q;
        q.push(root);
        int ind = 0; 
        while(!q.empty()){
            int sz = q.size();
            vector<int>temp;
            while(temp.size()!=sz){
            TreeNode* top = q.front();
            q.pop();
            temp.push_back(top->val);
            if(top->right) q.push(top->right);
            if(top->left) q.push(top->left);
            }
            if(temp.size()==sz){
                
                reverse(temp.begin(),temp.end());
                // for(auto x : temp){
                //     cout << x << " ";
                // }
                // cout << "->" << ind << endl;
                if(!checkOddEven(temp,ind)){
                    return false;
                }
            }
          
            ind++;
            temp.clear();
        }
        return true;
    }
};