class Solution {
public:
    
    bool checkSorted(vector<int>&nums){
        vector<int>temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());
        for(int i = 0; i < temp.size(); i++){
            if(temp[i]!=nums[i]){
                return false;
            }
        }
        return true;
    }
    
    int oneBits(int num){
        int count = 0;
        while(num>0){
            count+=num&1;
            num>>=1;
        }
        return count;
    }
    
    bool canSortArray(vector<int>& nums) { // [3,16,8,4,2]    8, 8 , 2
        // cout << oneBits(30) << "  " << oneBits(15) << endl;
        if(checkSorted(nums)) return true;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]<nums[i-1]){
                //swap - check if same set bits
                if(oneBits(nums[i])==oneBits(nums[i-1])){
                    swap(nums[i],nums[i-1]);
                    i= 0;
                    // for(auto x : nums){
                    //     cout << x << ' ';
                    // }
                    if(checkSorted(nums)) {
                        return true;
                    }
                    // else{
                    //     return false;
                    // }
                    // else{
                    // i=1;
                    // }
                }
                
                else{
                    return false;
                }
            }
        }
        if(checkSorted(nums)) return true;
        return false;
    }
    
};