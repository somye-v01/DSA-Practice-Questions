class Solution {
public:

    int solve(vector<int>& nums, int k){ //at most k characters
        int cnt = 0;
        unordered_map<int,int>m;
        int i = 0;
        int j = 0;
        int n = nums.size();
        while(j < n){
            m[nums[j]]++;
            while(m.size()>k){
                m[nums[i]]--;
                if(m[nums[i]]==0) m.erase(nums[i]);
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans1 = solve(nums,k);
        int ans2 = solve(nums,k-1);
        if (k > 1) {
            return ans1 - ans2;
        } else {
            return ans1;
        }
    }
};