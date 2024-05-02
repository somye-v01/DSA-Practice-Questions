class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int>s;
        for(auto x : nums){
            if (x<0){
                s.insert(x);
            }
        }
        int maxnum = -1;
        for(auto x : nums){
            if(x>0){
                if(s.find(-x)!=s.end()){
                    maxnum = max(maxnum,x) ;
                }
            }
        }
        return maxnum;
    }
};