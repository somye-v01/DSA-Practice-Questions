class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> s;
    
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            
            for(int j = i + 1; j < n ; j++){
                long long targetnew = static_cast<long long>(target) - nums[i] - nums[j];
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l){
                    if (nums[k] + nums[l] < targetnew ){
                        k++;
                    }
                    else if (nums[k] + nums[l] > targetnew ){
                        --l;
                    }
                    else if (nums[k] + nums[l] == targetnew){
                        s.insert(vector<int>{nums[i],nums[j],nums[k],nums[l]});
                        // ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        --l;
                    }

                }
            }
        }
        for (auto x : s){
            ans.push_back(x);
        }
        return ans;
    }
};