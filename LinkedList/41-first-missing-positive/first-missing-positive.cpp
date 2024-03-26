class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sm = 1;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]<=0){
                continue;
            }
            if(nums[i]==sm){
                while(i+1<nums.size() && nums[i+1]==sm){
                    i=i+1;
                }
                sm++;
            }
            else{
                // sm++;
                return sm;
            }
        }
        return sm;
    }
};