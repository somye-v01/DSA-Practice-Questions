class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        for(auto num : arr){
            m[num]++;
        }
        unordered_map<int,int>mp;
        for(auto it : m){
            mp[it.second]++;
        }
        for(auto it : mp){
            if(it.second>=2) return false;
        }
        return true;
    }
};