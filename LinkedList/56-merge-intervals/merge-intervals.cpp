class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(int i = 0; i < intervals.size(); i++){
            int low = intervals[i][0];
            int high = intervals[i][1];
            int j = i+1;
            while( j < intervals.size() && intervals[j][0] <= high ){
                high = max(high,intervals[j][1]);
                j++;
                i=j-1;
            }
            
            ans.push_back({low,high });
            // i+=j-1;
            // ans.push_back({intervals[i][0],intervals[i][1]});
            }
        return ans;
    }
};