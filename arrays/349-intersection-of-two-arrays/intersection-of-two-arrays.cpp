class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> ans;
        for (auto x : nums1){
            m[x] = 1;
        }
        for (auto x : nums2){
            if(m.find(x) != m.end()){
            m[x]++;
            }
        }
        for (auto& x : m){
            if(x.second > 1){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};