class Solution {
public:
    int minimumLength(string s) {
        int i = 0;
        int j = s.size()-1;
        while(j>=0 && i<=j ){
            if(s[i]!=s[j]){
                return j-i+1;
            }
            if(i==j) return 1;
            while(i+1 < s.size() && s[i]==s[i+1]){
                i=i+1;
            }
            while(j-1 >= 0 && s[j]==s[j-1]){
                j--;
            }
            i++;
            j--;
        }
        return 0;
    }
};