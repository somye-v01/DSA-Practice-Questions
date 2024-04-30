class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long cnt = 0;
        unordered_map<long long,long long>m;
        m[0] = 1; //0 already stored
        int xori = 0;
        for(char& ch : word){
            int ind = ch-'a';
            xori = xori ^ (1<<ind);
            cnt += m[xori];

            for(char c = 'a'; c <= 'j'; c++){
                int ind = c-'a';
                long long check_xor = xori ^ (1<<ind);
                cnt+=m[check_xor];
            }
            m[xori]++;
        }
        return cnt;
    }
};