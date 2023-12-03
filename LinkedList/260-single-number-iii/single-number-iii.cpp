class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto x : nums){
            m[x]++;
        }
        vector<int> ans;
        for(auto it : m){
            if(it.second == 1){
                ans.push_back(it.first);
            }
            if(ans.size()==2){
                break;
            }
        }
        return ans;
    }
};