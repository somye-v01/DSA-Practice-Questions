class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool flag = false;
        int indextoswap = -1;
        int indextoswapwith = -1; 
        for(int k = nums.size()-1; k>=0 ; k--){
            int n = nums[k];
        for(int i = k-1; i>=0; i--){
            if(nums[i] < n){ //next smaller elem
            flag = true;
            if(indextoswapwith < i){
                indextoswap = k;
                indextoswapwith = i;
            }
                // swap(nums[i], nums[k]);
                // sort(nums.begin()+i+1, nums.end());
                // flag = true;
                // break;
            }
        }
    }
    
    if(flag==false) sort(nums.begin(),nums.end());
    else{
    swap(nums[indextoswap], nums[indextoswapwith]);
    sort(nums.begin()+ indextoswapwith +1, nums.end());
    }
    }
};