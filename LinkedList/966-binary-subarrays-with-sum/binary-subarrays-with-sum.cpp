class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>m;
        m[0]=1;
        int sum = 0;
        int cnt = 0;
        for(auto num : nums){
            sum+=num;
            if(m.find(sum-goal)!=m.end()){
                cnt+=m[sum-goal];
            }
            m[sum]++;
        }
        return cnt;
    }
};