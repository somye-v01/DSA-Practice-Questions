class Solution {
public:

    int solve(int r_ind, int k_ind, string ring, string key, vector<vector<int>>& dp ){
        if( k_ind >= key.size()) return 0;
        if(dp[r_ind][k_ind] != -1) return dp[r_ind][k_ind];
        int ans = INT_MAX;
        for(int i = 0; i < ring.size(); i++){
            if(ring[i]==key[k_ind]){
                int op1 = ( abs(i - r_ind) +1 ) + solve(i,k_ind+1,ring,key,dp);
                int op2 = (ring.size() - abs(i - r_ind) +1 ) + solve(i,k_ind+1,ring,key,dp);
                ans = min(ans,min(op1,op2));
            }
        }
        dp[r_ind][k_ind] = ans;
        return dp[r_ind][k_ind] ;
    }

    int findRotateSteps(string ring, string key) {
        vector<vector<int>>dp(ring.size()+1,vector<int>(key.size(),-1));
        return solve(0,0,ring,key,dp);
    }
};