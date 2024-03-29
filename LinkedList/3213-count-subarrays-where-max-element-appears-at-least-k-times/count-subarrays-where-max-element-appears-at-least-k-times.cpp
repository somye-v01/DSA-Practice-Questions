class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // long long maxi = 0;
        long long maxi = *max_element(nums.begin(), nums.end());
        // cout<<"maxi here is: "<<maxi<<endl; 
        int i = 0;
        int j = 0;
        int n = nums.size();
        long long cnt = 0;
        long long cnt_maxi = 0;
        while(j<n){
            if(nums[j]==maxi) cnt_maxi++;
            while(cnt_maxi>=k){
                cnt+=n-j;
                if(nums[i]==maxi){
                    cnt_maxi--;
                }
                i++;
            }
            j++;
        }
        return cnt;
    }
};