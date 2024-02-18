class Solution {
public:

    int solve(string& word1, string& word2,int i, int j, vector<vector<int>>&dp){
        if(i>=word1.size()) return word2.size() - j;
        if(j>=word2.size()) return word1.size() - i;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if(word1[i]==word2[j]){
            dp[i][j] = solve(word1,word2,i+1,j+1,dp);
            return dp[i][j];
        }
        else{
            int op1 = solve(word1,word2,i,j+1,dp); //insert a char in shorter word
            int op2 = solve(word1,word2,i+1,j,dp);
            int op3 = solve(word1,word2,i+1,j+1,dp);
            dp[i][j] = ( 1 + min(op1,min(op2,op3)) );
            return dp[i][j] ;
        }
        
    }       

    int minDistance(string word1, string word2) {
        //word1 > word2
        // if(word1.length() >= word2.length()){
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size(),-1));
        return solve(word1,word2,0,0,dp);
        // }
        // else{
        //     return solve(word2,word1,0,0);
        // }
    }
};