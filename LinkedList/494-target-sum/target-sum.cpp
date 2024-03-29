class Solution {
public:

    int solve(vector<int>& nums, int target, int i){
        if(i>=nums.size()){
            if(target==0) return 1;
            return 0;
        }
        //ek time plus
        int plus = nums[i] + solve(nums,target-nums[i],i+1);
        int minus = -nums[i] + solve(nums,target+nums[i],i+1);
        return plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0);
    }
};