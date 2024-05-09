class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long ans = 0;
        int temp = 0;
        for(int i = 0; i < happiness.size() && k>0; i++,k--){
            ans += max(0,happiness[i]-temp);
            temp++;
        }
        return ans;

    }
};