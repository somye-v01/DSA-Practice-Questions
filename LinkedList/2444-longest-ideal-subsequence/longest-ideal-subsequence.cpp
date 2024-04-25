class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int>freq(26,0);
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            int ind = s[i] - 'a';
            int leftind = max(0,ind-k);
            int rightind = min(25,ind+k);
            int large = 0;
            for(int j = leftind; j <= rightind ; j++ ){
                large = max(large, freq[j]);
            }
            freq[ind] = max(freq[ind],large+1 );
            ans = max(ans,freq[ind]);
        }
        return ans;
    }
};