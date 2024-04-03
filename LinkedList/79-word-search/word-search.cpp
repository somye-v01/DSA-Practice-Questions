class Solution {
public:

    bool solve(int i, int j, int n, int m, int k, vector<vector<char>>& board, string word){
        if(k==word.size()) return true;
        if(i>=n || i<0 || j<0 || j >= m || board[i][j]!=word[k]){
            return false;
        }
        char ch = board[i][j];
        board[i][j] = '#';
        bool b1 = solve(i+1,j,n,m,k+1,board,word);
        bool b2 = solve(i,j+1,n,m,k+1,board,word);
        bool b3 = solve(i-1,j,n,m,k+1,board,word);
        bool b4 = solve(i,j-1,n,m,k+1,board,word);
        board[i][j] = ch;
        return b1||b2||b3||b4;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(); //no of rows
        int m = board[0].size(); //no. of columns
        int k = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(solve(i,j,n,m,k,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};