class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //n - k largest
        priority_queue<int> pq;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                pq.push(matrix[i][j]);
            }
        }
        int n = pq.size();
        for(int i = 0; i < n - k; i++){
            pq.pop();
        }  
        return pq.top();      
    }
};