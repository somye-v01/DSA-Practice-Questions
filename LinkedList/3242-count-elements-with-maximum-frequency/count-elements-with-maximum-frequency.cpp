class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto x : nums){
            m[x]++;
        }
        int maxi = 0;
        int cnt = 0;
        for(auto it : m){
            if(it.second>maxi){
                maxi = it.second;
                cnt = 0;
                cnt+=it.second;
            }
            else if(it.second == maxi){
                cnt+=it.second;
            }
        }
        return cnt;
    }
};