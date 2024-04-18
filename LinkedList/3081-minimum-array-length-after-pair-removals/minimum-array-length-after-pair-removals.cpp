class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int i = 0;
        // int j = i + 1;
        int n = nums.size();
        // if(n==2){
        //     return (nums[0]==nums[1] ? 2 : 0);
        // }
        int mid = (n%2 == 0 ? (n/2)-1 : n/2);
        // cout << "val of mid here is: "<<mid;
        int j = mid+1;
        while(i < mid+1 && j < n){
            if(nums[i] != nums[j]){
                nums[i] = -1;
                nums[j] = -1;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        int cnt = 0;
        for(int i =0; i < n; i++){
            if(nums[i]!=-1){
                cnt++;
            }
        }
        return cnt;
    }
};