class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        // int cnt = 0;
        int ans = 0;
        while(!q.empty()){
            auto top = q.front();
            // cnt++;
            q.pop();
            int x = top.first.first;
            int cnt = top.second;
            int y = top.first.second;
            int dx[] = {-1,1,0,0};
            int dy[] = {0,0,1,-1};
            for(int i = 0; i < 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY]==1){
                    q.push({{newX, newY}, cnt+1});
                    ans = max(ans,cnt+1);
                    grid[newX][newY] = 2;
                }
            }
        }
        // return cnt;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};