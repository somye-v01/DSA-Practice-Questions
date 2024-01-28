class Solution {
public:
    bool check(string str,vector<string>& wordDict){
        for(auto st : wordDict){
            if(st==str) return true;
        }
        return false;
    }
    bool solve(string s, vector<string>& wordDict, int i,vector<int>&dp){
        if(i>=s.size()) return true;
        if(dp[i]!=-1) return dp[i];
        //include
        string wd = "";
        bool flag = false;
        for(int j = i; j < s.size(); j++){
            wd+=s[j];
            if(check(wd,wordDict)){
                flag = flag || solve(s,wordDict,j+1,dp);
            }
        }
        dp[i] = flag;
        return dp[i];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(),-1);
        return solve(s,wordDict,0,dp);
    }
};