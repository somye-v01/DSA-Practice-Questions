class Solution {
public:

    int solve(vector<vector<int>>& cuboids,int prev,int curr, vector<vector<int>>&dp){
        if(curr>=cuboids.size()) return 0;
        if (dp[curr][prev+1] != -1) return dp[curr][prev+1];
        int include = 0;
        //int include
        if(prev==-1 || (cuboids[prev][0] <= cuboids[curr][0] && cuboids[prev][1] <= cuboids[curr][1] && cuboids[prev][2] <= cuboids[curr][2])){
            include = cuboids[curr][2] + solve(cuboids,curr,curr+1,dp);
        }
        //exclude
        int exclude = solve(cuboids,prev,curr+1,dp);
        dp[curr][prev+1] = max(include,exclude);
        return dp[curr][prev+1];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto& v : cuboids){
            sort(v.begin(),v.end());
        }
        sort(cuboids.begin(),cuboids.end());
        vector<vector<int>>dp(cuboids.size()+1,vector<int>(cuboids.size()+1,-1));
        return solve(cuboids,-1,0,dp);
    }
};