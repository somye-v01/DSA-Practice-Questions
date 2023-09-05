// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int i = nums.size() - 1;
//         int n = nums.size();
//         while((nums[i-1] >= nums[i] )&& (i > 0)){
//             --i;
//         }
//         // if (i > 0){
//         swap(nums[i], nums[i-1]);
        
//         for(int j x= i; j > 0; j--){
//             if ((nums[j] > nums[i]) && nums[j] < nums[i-1]){
//                 swap( nums[j] , nums[i-1] );
//             }
//         }
//         sort(nums.begin()+i,nums.end());
        
//     }
    
// };

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        int n = nums.size();
        
        // Find the first decreasing element from the right
        while (i > 0 && nums[i-1] >= nums[i]) {
            --i;
        }
        
        if (i > 0) {
            // Find the smallest element to the right of i that is greater than nums[i-1]
            int j = n - 1;
            while (j > i && nums[j] <= nums[i-1]) {
                --j;
            }

            // Swap nums[i-1] and nums[j]
            swap(nums[i-1], nums[j]);
        }
        
        // Reverse the subarray to the right of i
        sort(nums.begin() + i, nums.end());
    }
};
