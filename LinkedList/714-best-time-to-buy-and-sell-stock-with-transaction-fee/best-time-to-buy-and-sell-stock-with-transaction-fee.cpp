class Solution {
public:

    int solve(vector<int>& prices, int fee, int i, bool canBuy,vector<vector<int>>&dp){
        if(i==prices.size()) return 0;
        if(dp[i][canBuy]!=-1) return dp[i][canBuy];
        int profit1 = 0;
        int profit2 = 0;
        // int profit  = 0;
        if(canBuy){
            int buyProfit1 = -prices[i] + solve(prices,fee,i+1,false,dp);
            int buyProfit2 =  solve(prices,fee,i+1,true,dp);
            profit1 = max(buyProfit1,buyProfit2);
        }
        else{
            int sellprofit1 = prices[i] + solve(prices,fee,i+1,true,dp) - fee;
            int sellprofit2 = solve(prices,fee,i+1,false,dp);
            profit2 = max(sellprofit1,sellprofit2);
        }
        dp[i][canBuy] = max(profit1,profit2);
        return dp[i][canBuy];
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(prices,fee,0,true,dp);
    }
};