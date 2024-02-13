class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        set<pair<int,pair<int,int>>>st;
        vector<vector<int>>efforts(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        st.insert({0,{0,0}});
        efforts[0][0] = 0;
        while(!st.empty()){
            auto top = *st.begin();
            st.erase(st.begin());
            int eff = top.first;
            int x = top.second.first;
            int y = top.second.second;
            if(x==heights.size()-1 && y == heights[0].size()-1){
                return efforts[x][y];
            }
            int dx[] = {-1,1,0,0};
            int dy[] = {0,0,1,-1};
            for(int i = 0; i < 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >= 0 && newX < heights.size() && newY >= 0 && newY < heights[0].size()){
                    int neweff = abs(heights[newX][newY] - heights[x][y]);
                    int newmaxeff = max(neweff,eff);
                    if(newmaxeff < efforts[newX][newY]){
                        efforts[newX][newY] = newmaxeff;
                        st.insert({newmaxeff, {newX,newY}});
                    }
                }
            }
        }
        return 0;
    }
};