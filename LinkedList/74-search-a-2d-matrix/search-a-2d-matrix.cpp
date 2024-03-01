class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); //n=1
        int m = matrix[0].size(); //m=2
        int i = 0;
        if(matrix[n-1][m-1]<target) return false;

        while(i < n && matrix[i][m-1]<target){
            i++;
        }

        // cout << "reached here" << endl;
        int low = 0;
        int high = m-1; //high = 1
        while(low<=high){
            int mid = low+(high-low)/2;
            // cout << "calculated mid" << mid << " " << i << " " << matrix[i][mid] << " "<<endl;
            if(matrix[i][mid]==target) return true;
            if(matrix[i][low] > target) return false;
            if(matrix[i][mid] < target){
                // cout << "comparing" << endl;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
};