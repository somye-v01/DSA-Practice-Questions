class Solution {
public:

    int solve(int amount, vector<int>& coins, int index, vector<vector<int>>& dp){
        if(amount==0) return 1;
        if(amount<0 || index < 0) return 0;
        if(dp[index][amount] != -1) return dp[index][amount];
        int ans = 0;
        int include = 0;
        if(amount-coins[index]>=0){
            include = solve(amount-coins[index],coins,index,dp);
        }
        int exclude = solve(amount,coins,index-1,dp);
    
        dp[index][amount] = include+exclude;
        return dp[index][amount];
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans = solve(amount,coins,coins.size()-1,dp); 
        return ans;
    }
};