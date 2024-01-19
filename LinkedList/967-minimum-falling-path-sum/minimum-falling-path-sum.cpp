class Solution {
public:

    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>&dp ){
        if(i==matrix.size() - 1 ) return matrix[i][j];
        // if(i>=matrix.size()) return INT_MAX;
        if(j<0 || j>=matrix.size()) return 1e5;
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int ans = INT_MAX;
        int op1 = INT_MAX;
        if(j-1>=0 && i<matrix.size()){
         op1 = matrix[i][j] + solve(matrix,i+1,j-1,dp);
        }
        int op2 = matrix[i][j] + solve(matrix,i+1,j,dp);
        int op3 = INT_MAX;
        if(j+1<matrix.size()&&i<matrix.size()){
         op3 = matrix[i][j] + solve(matrix,i+1,j+1,dp);
        }
        dp[i][j] = min(op1,min(op2,op3));
        return dp[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix.size()+1,INT_MIN));
        for(int i = 0; i < matrix.size();i++){
            ans = min(ans,solve(matrix,0,i,dp));
        }
        return ans;
    }
};