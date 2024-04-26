class Solution {
public:

    int solve(int colig, int i, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == grid.size() ) return 0;
        if(dp[colig][i] != -1) return dp[colig][i];
        int ans = INT_MAX;
        for(int col = 0; col < grid.size(); col++){
            if(col!=colig){
                ans = min(ans, grid[i][col] + solve(col, i+1, grid,dp));
            }
        }
        dp[colig][i] = ans;
        return dp[colig][i] ;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int n = grid.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i = 0; i < n; i++){
            ans = min(ans, grid[0][i] + solve(i, 1, grid,dp));
        }
        return ans;
    }
};