class Solution {
public:
    int rob_helper(vector<int>& nums, int i,vector<int>& dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int sum = 0;
        //ya to mai ith ghar rob karunga
        int amt1 = nums[i]+rob_helper(nums,i+2,dp);

        //ya ith ghar rob nahi karunga
        int amt2 = 0+rob_helper(nums,i+1,dp);

        dp[i] = max(amt1, amt2);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        int i = 0;
        int ans = rob_helper(nums,i,dp);
        return ans;
    }
};