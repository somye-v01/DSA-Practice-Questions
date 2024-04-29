class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int>rowsum(n,0);
        vector<int>colsum(m,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                rowsum[i]=rowsum[i]+grid[i][j];
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                colsum[i]=colsum[i]+grid[j][i];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j]==1 && rowsum[i]-1>0 && colsum[j]-1>0){
                    ans+=(rowsum[i]-1)*(colsum[j]-1);
                }
            }
        }
        return ans;
    }
};