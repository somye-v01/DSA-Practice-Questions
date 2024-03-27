class Solution {
public:

    void helper(vector<int>& nums, int n, int ind,vector<int>& temp, set<vector<int>>&s){
        if(ind>=n) {
            // sort(temp.begin(),temp.end());
            s.insert(temp);
            return;
        }
        //pick
        temp.push_back(nums[ind]);
        helper(nums, n, ind + 1, temp, s);
        temp.pop_back(); 
        //not pick
        helper(nums,n,ind+1,temp,s);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>s;
        vector<int>temp;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        helper(nums,n,0,temp,s);
        vector<vector<int>> ans;
        for(auto x : s){
            ans.push_back(x);
        }
        return ans;
    }
};