class Solution {
public:
  
  int mincostTicketsHelper(vector<int>& days, vector<int>& costs,int i ,vector<int>&dp ){
      if(i >= days.size()) return 0;
        if(dp[i]!=-1) return dp[i];
      int cost = 0;
     
        int temp1 = costs[0] + mincostTicketsHelper(days,costs,i+1,dp);
        // int temp2 = 0;
        int j = i;
        while (j < days.size() && days[j] < days[i] + 7) j++;
        int temp2 = costs[1]+mincostTicketsHelper(days,costs,j,dp);
        j = i;
        while (j < days.size() && days[j] < days[i] + 30) j++;
        int temp3 = costs[2]+mincostTicketsHelper(days,costs,j,dp);
        
        cost = min(temp1,min(temp2,temp3));
        dp[i] = cost;
        return dp[i];
  }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        return mincostTicketsHelper(days,costs,0,dp);
    }
};