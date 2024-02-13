class Solution {
public:

    void dfs(vector<vector<int>>& image, int x, int y, int color, map<pair<int,int>,bool>& vis){
        vis[{x,y}] = true;
        int tempcol = image[x][y];
        image[x][y] = color;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX>=0 && newX < image.size() && newY>=0 && newY < image[0].size() && !vis[{newX,newY}] && image[newX][newY]==tempcol){
                dfs(image,newX,newY,color,vis);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        map<pair<int,int>,bool>vis;
        dfs(image,sr,sc,color,vis);
        return image;
    }
};