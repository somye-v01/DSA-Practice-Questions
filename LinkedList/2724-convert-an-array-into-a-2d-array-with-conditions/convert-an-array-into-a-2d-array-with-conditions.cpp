class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums){
        vector<vector<int>> ans;
        unordered_map<int,int> m;
        int row = INT_MIN;
        for(auto num : nums){
            m[num]++;
            row = max(row,m[num] );
        }
        for(int i = 0; i < row; i++){
        vector<int> temp;
        for(auto it : m){
            cout << it.first << " " <<it.second<<endl;
            if(m[it.first]>0){
                temp.push_back(it.first);
                m[it.first]--;
            }

            }
            ans.push_back(temp);
        }
        
return ans;
    }
    
};