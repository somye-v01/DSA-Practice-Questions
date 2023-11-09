class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        long long int res = 0;
        while ( i < n ){
            int count = 0;
            j = i;
            while(j < n && s[i] == s[j]){
                count++;
                res += count;
                j++;
            }
            i = j;
        }
        int mod = 1e9 + 7;
         res =  res%mod;
         return res;
    }
};