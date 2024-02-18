class Solution {
public:

    int solve(vector<int>& cost, int i, int n, vector<int>&dp){
        if(i>=n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int cost1 = cost[i] + solve(cost,i+1,n,dp);
        int cost2 = INT_MAX;
        if(i+1<n){
         cost2 = cost[i+1] + solve(cost,i+2,n,dp);
        }
        int ttlcost = min(cost1,cost2);
        dp[i] = ttlcost;
        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n =  cost.size();
        vector<int>dp(n+1,-1);
        return solve(cost,0,n,dp);
        // int ans2 = solve(cost,1,n);
        // return min(ans1,ans2);
    }
};