class Solution {
public:

    void dfstravel(vector<vector<int>>& isConnected, int i , unordered_map<int,bool>&vis){
        vis[i] = true;
        for(int col = 0; col < isConnected[i].size(); col++ ){
            if(i!=col && isConnected[i][col]==1 && !vis[col]){
                // if(){
                    dfstravel(isConnected, col, vis);
                // }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool>vis;
        int cnt = 0;
        for(int i = 0; i < isConnected.size(); i++){
            if(!vis[i]){
                dfstravel(isConnected, i, vis);
                cnt++;
            }
        }
        return cnt;
    }
};