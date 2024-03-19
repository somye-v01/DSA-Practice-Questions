class Solution {
public:

    bool solve(string& s, string& p, int i, int j, vector<vector<int>>&dp){
        if(i>s.size() || j>p.size()) return false;
        if(i==s.size() && j==p.size()){
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j] = solve(s,p,i+1,j+1,dp);
        }
        if(p[j]=='*'){
            bool case1 = solve(s,p,i,j+1,dp);
            bool case2 = solve(s,p,i+1,j,dp);
            dp[i][j] = case1||case2;
            return dp[i][j];
        }
        return false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return solve(s,p,0,0,dp);
    }
};