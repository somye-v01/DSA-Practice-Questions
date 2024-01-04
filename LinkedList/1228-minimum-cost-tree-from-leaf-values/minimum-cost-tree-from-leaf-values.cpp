class Solution {
public:

    int solve(int left,int right, map<pair<int,int>,int>&m,vector<vector<int>>&dp){
        if(left==right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int ans = INT_MAX;
        for(int i = left;i<right;i++){
            ans = min(ans, m[{left,i}]*m[{i+1,right}]+solve(left,i,m,dp)+solve(i+1,right,m,dp) );
        }
        dp[left][right] = ans;
        return dp[left][right];
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int>m; //range - largest_element
        for(int i = 0; i < arr.size(); i++){
            m[{i,i}] = arr[i];
            for(int j = i+1; j < arr.size(); j++){
                m[{i,j}] = max(arr[j],m[{i,j-1}]);
            }
        }
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
        int ans = solve(0,arr.size()-1,m,dp); //ans = min(ans,max(m[start,i],m[i+1,end]))+solve(left,i)+solve(i+1,right));
        return ans;
    }
};