class Solution {
public:

    void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int> temp,int index){
        //include
        if(index==nums.size()){
            ans.push_back(temp);
            return;
        }
        //exclude
        solve(nums,ans,temp,index+1);
        //include
        int num = nums[index];
        temp.push_back(num);
        solve(nums,ans,temp,index+1);
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        //include-exclude
        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0;
        solve(nums,ans,temp,index);
        return ans;
    }
};