class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans(n);
        int i = 0;
        while (i<n){
            for(int j = 0; j < n; j +=2){ //sort krke new arr me dal dia but with a diff of 2 btw them.
                ans[j] = nums[i];
                i++;
            }
            for(int j = 1; j < n; j +=2){
                ans[j] = nums[i];
                i++;
            }

        }
        return ans;
    }
        
    
};