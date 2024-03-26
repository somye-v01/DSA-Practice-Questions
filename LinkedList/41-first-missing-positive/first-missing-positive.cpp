class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool onef = false;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==1){
                onef = true;
            }
        }
        if(!onef) return 1;
        int n = nums.size();
        for(int i = 0; i < nums.size();i++){
            if(nums[i] <= 0 || nums[i]>n) nums[i]=1;
        }
        for(int i = 0; i < nums.size(); i++){
            int num = abs(nums[i]);
            if(nums[num-1]>0){
                nums[num-1]= -nums[num-1];
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i]>0){
                // cout<<"number im getting here is: "<<nums[i]<<endl;
                return i+1;
            }
        }
        return n+1;
    }
};