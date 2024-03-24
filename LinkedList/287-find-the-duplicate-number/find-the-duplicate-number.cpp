class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> m;
        for(auto x : nums){
            if(m.find(x)!=m.end()){
            return x;
            }
            else{
                m[x]++;
            }
        }
        return ans;
    }
};