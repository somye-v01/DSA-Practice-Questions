class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> ans;
        for (auto x : nums1){
            m[x] = 10;
        }
        for (auto x : nums2){
            m[x]++;
        }
        for (auto& x : m){
            if(x.second > 10){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};