class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1;
        bool fl = false;
        bool con = false;
        int cnt = 0;
        while(n>=0 && !fl){
            if(isalpha(s[n])){
                cnt++;
                con = true;
            }
            
            if(con && s[n]==' '){
            fl = true;
            }
            n--;
        }
        return cnt;
    }
};