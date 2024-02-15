class Solution {
public:

    // bool checkPolygon(vector<int>& nums){

    // }

    long long largestPerimeter(vector<int>& nums) {
        vector<long long>sumNums(nums.size(),0);
        sort(nums.begin(),nums.end());
        sumNums[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sumNums[i] = sumNums[i-1] + nums[i];
        }
        // int sum = 0;
        // for(int i = 0 ; i < nums.size(); i++){
        //     sum+=nums[i];
        // }
        // for(auto x : sumNums){
        //     cout << x << ' ';
        // }
        long long i = sumNums.size()-1;
        while(i>=2){
            if(sumNums[i-1] > nums[i] ){
                return sumNums[i];
            }
            i--;
        }
        return -1;
    }
};