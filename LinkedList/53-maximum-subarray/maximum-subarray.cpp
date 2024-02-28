class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;
        for(int i =0; i < nums.size(); i++){
            sum+=nums[i];
            ans = max(ans,sum);
            if(sum<0) sum=0;
            // int temp = 0;
            // if(nums[i]>0){
            //     temp+=nums[i];
            //     while(i < nums.size() && temp>0){
            //         ans = max(ans,temp);
            //         i++;
            //         temp+=nums[i];
            //         // if(i==nums.size()-1) break;
            //     }
            // }
        }
        return ans;
    }
};