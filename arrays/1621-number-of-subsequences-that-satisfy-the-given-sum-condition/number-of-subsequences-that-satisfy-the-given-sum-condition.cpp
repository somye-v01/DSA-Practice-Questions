class Solution {
public:

    int power(long long a, int n, const int MOD){
       int ans = 1;
        while (n > 0) {
            if (n & 1) {
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            n = n >> 1;
        }
        return ans;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        long long count = 0;
        const int MOD = 1e9 + 7;


        while ( i <= j ){
            int sum = nums[i] + nums[j];
            if (sum <= target){
                count = ((count + power(2, (j-i),MOD))%MOD); //count += count + pow(2,j-i)
                i++;
            }
            else{
                --j;
            }

        }
        return count;
    }
};