class Solution {
public:

    void bfs(vector<vector<char>>& grid, map<pair<int,int>,bool>&vis, int row,int col){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[{row,col}] = true;
        while(!q.empty()){
            auto cord = q.front();
            q.pop();
            int x = cord.first;
            int y = cord.second;
            int dx[] = {-1,1,0,0};
            int dy[] = {0,0,1,-1};
            for(int i = 0; i < 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if( newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && !vis[{newX,newY}] && grid[newX][newY]=='1'){
                    q.push({newX,newY });
                    vis[{newX, newY}] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        map<pair<int,int>,bool>vis;
        int n = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < n; j++){
                if(!vis[{i,j}] && grid[i][j]=='1'){
                    bfs(grid,vis,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};