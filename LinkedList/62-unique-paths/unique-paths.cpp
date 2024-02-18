class Solution {
public:

    int solve(int m, int n, int j, int i, vector<vector<int>>&dp){
        if(j>=n || i>=m){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = solve(m,n,j+1,i,dp) + solve(m,n,j,i+1,dp);
        // ans += 1+solve(m,n,j,i+1);
        dp[i][j] = ans;
        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m,n,0,0,dp);
    }
};