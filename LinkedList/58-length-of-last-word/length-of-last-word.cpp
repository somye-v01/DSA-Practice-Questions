class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        int cnt=0;
        bool fl = false;
        for(int i = 0; i < s.size(); i++){
            if(isalpha(s[i])){
                cnt++;
                fl = true;
            }
            else if(fl==true){
                break;
            }
        }
        return cnt;
    }
};