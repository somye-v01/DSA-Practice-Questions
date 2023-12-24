class Solution {
public:
    int minOperations(string s) {
        string st = s;
        int ans = 0;
        int cnt = 0;
        int tempcount = 0;
        for(int i = 0; i < s.size()-1; i++){
           
            if(s[i]==s[i+1]){
                cnt++;
                s[i + 1] = s[i + 1] ^ 1;
            }

        }

        string t = s;
        t[0] = t[0]^1;
        for(int i = 1; i < t.size(); i++){
            t[i] = t[i]^1;
        }
        for(int i = 0; i < t.size(); i++){
            if(st[i]!=t[i]){
                tempcount++;
            }
        }
        cout << t << endl;
        return min(tempcount,cnt);

    }
};