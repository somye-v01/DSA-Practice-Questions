class Solution {
private:
    int maxSubArray(vector<int>& nums, int low, int high){
        if(low == high){
            return nums[low];
        }
        int leftMaxSumSubarray = INT_MIN, rightMaxSumSubarray = INT_MIN;

        int mid = (low + high) >> 1;
        int currSum = 0;
        for(int i=mid; i>=low; i--){
            currSum += nums[i];
            leftMaxSumSubarray = max(leftMaxSumSubarray, currSum);
        }

        currSum = 0;
        for(int i=mid+1; i<=high; i++){
            currSum += nums[i];
            rightMaxSumSubarray = max(rightMaxSumSubarray, currSum);
        }

        int maxSumSubarray =  leftMaxSumSubarray +  rightMaxSumSubarray;
        int leftAnsSum = maxSubArray(nums, low, mid);
        int rightAnsSum = maxSubArray(nums, mid+1, high);

        return max(maxSumSubarray, max(leftAnsSum, rightAnsSum));
    }
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size()-1);
    }
};