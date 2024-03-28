class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        //2 pointer
        //i & j starting from 0, if j reaches end, or freq[j]>k => i++
        int i = 0;
        int j = 0;
        int n = nums.size();
        int maxi = 0;
        unordered_map<int,int>m;
        int len = 0;
        while(j<n){
            // if(m.find(nums[j])==m.end() && k >= 1){
                m[nums[j]]++;
                // len++;
            // }
            // else if( m.find(nums[j])!=m.end() && m[nums[j]] < k ){
            //     m[nums[j]]++;
            //     // len++;
            // }
            // else{
                // maxi=max(maxi,len);
                // len=0;
                // // len-=1;
                // // m[nums[j]]--;
                // m.clear();
                // m[nums[j]]++;
                // len++;
                while(m[nums[j]]>k){
                    m[nums[i]]--;
                    i++;
                }
            
            len=j-i+1;
            maxi=max(maxi,len);
            j++;
        }
        if(maxi<len) maxi=len;
        return maxi;
    }
};