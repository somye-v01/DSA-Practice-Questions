class Solution {
public:

    bool isSafe(int row,int col,int n,vector<vector<char>>&board){
        int row2 = row;
        int col2 = col;
        int r = row;
        while(r>=0){
            if(board[r][col]=='Q'){
                return false;
            }
            r--;
        }
        int c = col;
        while(c>=0){
            if(board[row][c]=='Q'){
                return false;
            }
            c--;
        }
        //upper left diag
        while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row = row2;
        col = col2;
        //lower left diag
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }

    void store(vector<vector<char>>&board, vector<vector<string>>&ans,int n){
        vector<string>temp;
        for(int i = 0; i < n; i++){
            string out = "";
            for(int j = 0; j < n; j++){
                out.push_back(board[i][j]);
            }
            temp.push_back(out);
        }
        ans.push_back(temp);
    }

    void solve(vector<vector<char>>&board, vector<vector<string>>&ans, int col, int n){
        if(col>=n){
            store(board,ans,n);
            return;
        }
        for(int i = 0; i < n; i++){
            if(isSafe(i,col,n,board)){
                board[i][col] = 'Q';
                solve(board,ans,col+1,n);
                board[i][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>board(n,vector<char>(n,'.'));
        vector<vector<string>> ans;
        int col = 0;
        solve(board,ans,col,n);
        return ans;
    }
};