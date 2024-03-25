class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        if(nums.empty())return {};
        for(int i = 0; i < nums.size();i++){
           
            int num = abs(nums[i]); // i = 0; el = 1
             if(nums[abs(nums[i])-1]<0){
                ans.push_back(abs(nums[i]));
                continue;
            }
            
            nums[(num)-1] = -nums[(num)-1];
        }
        return ans;
    }
};

// unordered_map<int,int> m;
//         for(int n : nums){
//             m[n]++;
//         }
//         for(auto it : m){
//             if(it.second == 2){
//                 ans.push_back(it.first);
//             }
//         }
