class Solution {
public:

    // int calc(set<int> s){
    //     int res = 0;
    //     for(auto it = s.begin(); it ! s.end(); it++){
    //         res+=*it;
    //     }
    //     return res;
    // }

    int minCost(string colors, vector<int>& neededTime) {
        int i = 0;
        int j = 1;
        int n = colors.size();
        int ans = 0;
        int cost = INT_MAX;
        // set<int>temp;
        while(i<n && j<n){
            if(colors[i]==colors[j]){
                // cost = min(cost,min(neededTime[i],neededTime[j] ) );
                int mini = min(neededTime[i],neededTime[j]);
                if(mini == neededTime[i]){
                    ans+=mini;
                    i=j;
                    j++;
                }
                else{
                    ans+=mini;
                    j++;
                }

            }
            else{
                i=j;
                j++;
            }


        }
        // for(int i = 0; i < colors.size(); i++){

        // }
        return ans;
    }
};