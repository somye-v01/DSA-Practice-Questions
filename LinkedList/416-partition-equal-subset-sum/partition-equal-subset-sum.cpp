class Solution {
public:

    bool solve(vector<int>& nums, int target, int index,vector<vector<int>>&dp){
        if(index<0) return false;
        if(target==0) return true;
        if(index!=0 && target==0) return false;
        if(index==0 && target!=0) return false;
        if(dp[index][target]!=-1) return dp[index][target];
        bool include = false;
        if(target-nums[index]>=0){
         include = solve(nums,target-nums[index],index-1,dp);
        }
        bool exclude = solve(nums,target,index-1,dp);
        dp[index][target] = (include || exclude);
        return dp[index][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x : nums){
            sum+=x;
        }
        
        if(sum%2==1) return false;
        int target = sum/2;
        int n = nums.size();
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        int ans = solve(nums,target,n-1,dp);
        return ans;
    }
};