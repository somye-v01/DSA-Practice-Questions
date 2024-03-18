class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[&](vector<int>a,vector<int>b){
            return a[1]<b[1];
        });
        // for(auto x : points){
        //     cout<<x[0]<<" "<<x[1]<<" and ";
        // }
        int ans = 1;
        // int maxi = INT_MAX;
        int st = points[0][1];
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] <= st){
                continue;
            }
            else{
                ans++;
                st = points[i][1];
            }
        }
        // if(maxi==INT_MAX) ans++;
        return ans;
    }
};