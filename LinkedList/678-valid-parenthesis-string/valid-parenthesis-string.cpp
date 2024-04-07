class Solution {
public:

    bool solve(string &s, int i, int opencnt, int n, vector<vector<int>>& dp){
        if(i>=n) return opencnt == 0;
        if(dp[i][opencnt]!=-1) return dp[i][opencnt];
        bool valid = false;
        if(s[i]=='*'){
            valid = valid | solve(s,i+1,opencnt+1,n,dp);
            valid = valid | solve(s,i+1,opencnt,n,dp);
            if(opencnt>0){
                valid = valid | solve(s,i+1,opencnt-1,n,dp);
            }
        }
        else if(s[i] == '('){
            valid = valid | solve(s,i+1,opencnt+1,n,dp);
        }
        else if(opencnt>0){
            valid = valid | solve(s,i+1,opencnt-1,n,dp);
        }
        return dp[i][opencnt] = valid;

    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(s,0,0,n,dp);
    }
};