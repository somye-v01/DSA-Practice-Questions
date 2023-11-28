class Solution {
public:

    int topDownDP(vector<int>& dp,int n){
        if(n==1) return 1;
        if(n==0) return 0;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];
        dp[n] = topDownDP(dp,n-1) + topDownDP(dp,n-2);
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int ans = topDownDP(dp,n);
        return ans;
    }
};