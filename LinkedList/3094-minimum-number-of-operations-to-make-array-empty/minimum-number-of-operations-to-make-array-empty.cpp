class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto x : nums){
            m[x]++;
        }
        int ans = 0;
        for(auto it : m){
            if(it.second == 1) return -1;
            ans+=it.second/3;
            if(it.second>=3){
            it.second = it.second - ((it.second/3)*3);
            }
            if(it.second>0) ans++;
        }
        return ans;
    }
};