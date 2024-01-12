class Solution {
public:
    int count(string s, int i, int j){
        int ans = 0;
        for(int k = i; k < j; k++){
            if(s[k]=='a' ||s[k]=='e'|| s[k]=='i' || s[k]=='o' || s[k]=='u' ){
                ans++;
            }
        }
        return ans;
    }

    bool halvesAreAlike(string s) {
        for(int i = 0; i < s.size(); i++){
            s[i] = tolower(s[i]);
        }
        // s = s.toLowerCase();
        int cnt1 = count(s,0,s.size()/2);
        int cnt2 = count(s,(s.size()/2),s.size());
        return cnt1==cnt2;
    }
};