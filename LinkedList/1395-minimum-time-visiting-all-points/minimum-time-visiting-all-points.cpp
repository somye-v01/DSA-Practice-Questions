class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i = 0; i < n-1 ;i++){
            int maxi = 0;
            for(int j = 0; j < points[i].size();j++){
                int diff = abs(points[i+1][j] - points[i][j]);
                maxi = max(maxi,diff);
            }
            ans+=maxi;
        }
        return ans;
    }
};