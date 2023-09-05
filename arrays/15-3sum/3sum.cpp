class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        vector<vector<int>> ans;
        vector<int> sol;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size()-2; i++){
            int newtarget = target - nums[i];
            int j = i + 1;
            int k = nums.size()-1;

            while(j < k){
                if (nums[j] + nums[k] == newtarget){
                    sol = {nums[i],nums[j],nums[k]};
                    s.insert(sol);
                    // ans.push_back(s);
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] > newtarget){
                    --k;
                }
                else{
                    ++j;
                }
            }
            // if(sol.size()!=0){
                 
            // }

           
        }
        ans.assign(s.begin(), s.end());
        return ans;
    }
};