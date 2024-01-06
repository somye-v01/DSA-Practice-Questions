class Solution {
public:

    int solve(vector<vector<int>>&arr, int index,vector<int>&dp){
        if(index>=arr.size()) return 0;
        //end time ke just baad wala start time konsa hai?
        int end = arr[index][1];
        if(dp[index]!=-1) return dp[index];
        // int j = arr[arr.size()-1][1];
        // while(i<j){

        // }
        // auto comp = []( vector<int>& v, int val) {
        //     return v[0] < val;
        // };
        // int newindex = upper_bound(arr.begin()+index,arr.end(),end,comp) - arr.begin();
        int newindex = 0;
        // for(int i = 0; i < arr.size(); i++){
        //     if(arr[i][0]>=end){
        //         newindex = i;
        //         break;
        //     }
        //     else{
        //         newindex = arr.size();
        //     }
        // }
        int s = index;
        int e = arr.size();
        int mid = 0;
        while(s < e){
             mid = s + (e-s)/2;
            if(arr[mid][0] >= arr[index][1]){
                e = mid;
                // newindex = mid;
            }
            else{
               s = mid+1;
            }
        }
        newindex = s;
        // newindex = mid;
        int include = arr[index][2] + solve(arr,newindex,dp) ;
        int exclude = solve(arr,index+1,dp);
        dp[index] = max(include,exclude);
        return dp[index];
    }

    // int solveTab(vector<vector<int>>&arr, int index){
    //     vector<int>dp(arr.size()+1,0);

    // }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
        /*  
         1-3 : 50
         2-4 : 10
         3-5 : 40
         3-6 : 70
        */
        vector<vector<int>>arr;
        for(int i = 0; i < startTime.size(); i++){
            arr.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(arr.begin(),arr.end());
        vector<int>dp(arr.size()+1,-1);
        int ans = solve(arr,0,dp);
        return ans;
    }
};