class Solution {
public:

    int solve(vector<int>& prices, int limit, bool canBuy, int i, vector<vector<vector<int>>>&dp){
        //0 => true, 1 => false
        if(i>=prices.size() || limit<=0) return 0;
        if (dp[limit][canBuy][i] != -1) return dp[limit][canBuy][i];
        int profit1 = 0;
        int profit2 = 0;
        if(canBuy==true){
            int buyProfit1 = -prices[i] + solve(prices,limit,false,i+1,dp);
            //ya to buy nahi kia
            int buyProfit2 = solve(prices,limit,true,i+1,dp);
            profit1 = max(buyProfit1,buyProfit2);
        }
        else{
            int sellProfit1 = prices[i] + solve(prices,limit-1,true,i+1,dp);
            int sellProfit2 = solve(prices,limit,false,i+1,dp);
            profit2 = max(sellProfit1,sellProfit2);
        }
        dp[limit][canBuy][i] = max(profit1,profit2);
        return dp[limit][canBuy][i];
    }

    int maxProfit(int k, vector<int>& prices) {
        bool canBuy = true;
        vector<vector<vector<int>>>dp(k+1,vector<vector<int>>(2,vector<int>(prices.size()+1,-1)));
        return solve(prices,k,canBuy,0,dp);
    }
};