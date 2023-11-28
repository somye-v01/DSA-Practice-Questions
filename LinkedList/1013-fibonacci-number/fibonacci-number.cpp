class Solution {
public:

    int topdown( int n, vector<int>& dp){
        if(n==1){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n] = topdown(n-1,dp) + topdown(n-2,dp);
        return dp[n];
    }

    int fib(int n) {
        vector<int> dp(n+1,-1);
        int ans = topdown(n,dp);
        return ans;
    }
};