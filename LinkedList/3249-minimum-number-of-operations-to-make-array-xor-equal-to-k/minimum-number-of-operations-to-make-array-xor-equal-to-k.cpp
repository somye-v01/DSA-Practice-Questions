class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = 0;
        for(int num : nums){
            n = n^num;
        }
        auto x = bitset<32>(n).to_string() ;
        auto y = bitset<32>(k).to_string();
        int cnt =0;
        for(int i = 0; i < 32; i++){
            if(x[i]!=y[i]){
                cnt++;
            }
        }
        return cnt;
    }
};