class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroRow = false;
        bool zeroCol = false;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size();j++){
                if(matrix[0][j]==0){
                    zeroRow = true;
                    break;
                }
                
            }
            break;
        }
        for(int i = 0; i < matrix.size(); i++){
            // for(int j = 0; j < matrix[0].size();j++){
                if(matrix[i][0]==0){
                    zeroCol = true;
                    break;
                }
        }

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
         for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size();j++){
                if(matrix[i][0] == 0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(zeroRow){
            for(int i = 0; i < matrix[0].size(); i++){
                matrix[0][i] = 0;
            }
        }
        if(zeroCol){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][0] = 0;
            }
        }
    }
};