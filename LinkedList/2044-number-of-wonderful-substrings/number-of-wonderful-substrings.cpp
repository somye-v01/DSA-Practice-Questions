class Solution {
public:
    long long wonderfulSubstrings(string word) {
        //ref to codestorywithmik

        //COMMULATIVE XOR CONCEPT
        long long cnt = 0;
        unordered_map<long long,long long>m;
        m[0] = 1; //0 already stored
        int xori = 0;
        for(char& ch : word){ // even occuring. if seen in map, increase the count.
            int ind = ch-'a'; //a = 0001, b = 0010, c = 0100, .... till j.
            xori = xori ^ (1<<ind);  //2 same number ka xor is 0.
            cnt += m[xori];

            for(char c = 'a'; c <= 'j'; c++){ //sare char se vps xor kro, jisse zero aae, that char is odd and occurs once.
                int ind = c-'a';
                long long check_xor = xori ^ (1<<ind);
                cnt+=m[check_xor];
            }
            m[xori]++;
        }
        return cnt;
    }
};