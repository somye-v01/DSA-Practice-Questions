class Solution {
public:
    int numSquaresHelper(int n,vector<int>&dp){
        //Base Case
        // int i = 1;
        if(n<=0){
            return 0;
        }
        // if(n<0){
        //     return 0;
        // }
        if(dp[n]!=-1) return dp[n];
       int ans= INT_MAX;
        for(int i = 1; i <= sqrt(n); i++){
            int perfectsquare = i*i;
            ans = min(ans,1 + numSquaresHelper(n-perfectsquare,dp));
        }
        dp[n] = ans;
        return dp[n];
        
    }
    
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        int ans = numSquaresHelper(n,dp);
        return ans;
    }
};