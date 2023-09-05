class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower); // convert all to lower case
        string res = "";
        for( char ch : s){
            if (isalnum(ch)){
                res += ch;
            }
        }
        int i = 0;
        int j = res.size() - 1;
        
        while(i <= j){
            if(res[i]!=res[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
};