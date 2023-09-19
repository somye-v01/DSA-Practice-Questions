class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> counts;
        for(int i = 0; i < mat.size();i++){
            int count = 0;
        
            for(int j = 0; j < mat[i].size(); j++){
               
                if(mat[i][j]==1){
                    count++;
                }
            }
             counts.push_back({count,i}) ;
        }
        sort(counts.begin(), counts.end());
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(counts[i].second);
        }
        // sort(counts.begin(),count.end());
        // counts.erase(counts.begin()+k,counts.end());
        return result;
    }
};