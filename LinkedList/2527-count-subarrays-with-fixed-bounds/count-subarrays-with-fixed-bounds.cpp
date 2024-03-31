class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long cnt = 0;
        int i = 0;
        int j = 0;
        int mini = -1;
        int maxi = -1;
        while(j < nums.size()){
            if(nums[j]>maxK || nums[j] < minK){
                i=j+1;
                mini = -1;
                maxi = -1;
            }
            if(nums[j]==minK){
                mini = j;
            }
            if(nums[j]==maxK){
                maxi = j;
            }
            cnt+=max(0, min(mini,maxi)-i+1);
            j++;
        }
        return cnt;
    }
};