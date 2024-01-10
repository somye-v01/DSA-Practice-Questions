class Solution {
public:

    int solve(vector<int>& prices,int i, int canBuy, int limit, vector<vector<vector<int>>>&dp){
        if(i>=prices.size() || limit<=0) return 0;
        if(dp[i][canBuy][limit]!=-1) return dp[i][canBuy][limit];
        int profit = 0;
        if(canBuy==0){
            int profit1 = -prices[i] + solve(prices,i+1,1,limit,dp);
            int profit2 = solve(prices,i+1,0,limit,dp);
            profit = max(profit1,profit2);
        }
        else{
            int sellprice1 = prices[i] + solve(prices,i+1,0,limit-1,dp);
            int sellprice2 = solve(prices,i+1,1,limit,dp);
            profit = max(sellprice1,sellprice2);
        }
        dp[i][canBuy][limit] = profit;
        return dp[i][canBuy][limit];
    }

    int maxProfit(vector<int>& prices) {
        //atmost 2 transactions
        int limit = 2;
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        int ans = solve(prices,0,0,limit,dp);
        return ans;
    }
};