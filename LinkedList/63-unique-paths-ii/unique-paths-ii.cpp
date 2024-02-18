class Solution {
public:

    int solve(vector<vector<int>>& obstacleGrid, int i, int j,vector<vector<int>>&dp){ //i => rows, j => columns
        // if(obstacleGrid[i][j]==1) return 0;
        if(i>=obstacleGrid.size() || j>=obstacleGrid[0].size() || obstacleGrid[i][j]==1 ){
            return 0;
        } 
        if(i==obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = solve(obstacleGrid,i+1,j,dp) + solve(obstacleGrid,i,j+1,dp);
        dp[i][j] = ans;
        return dp[i][j];
    }   

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp(obstacleGrid.size()+1,vector<int>(obstacleGrid[0].size()+1,-1));
        return solve(obstacleGrid,0,0,dp);
    }
};