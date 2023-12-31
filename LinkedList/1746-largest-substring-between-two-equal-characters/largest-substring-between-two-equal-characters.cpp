class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        cout << n << endl;
        if(n==1) return -1;
        int i = 0;
        int j = n-1;
        int longest = 0;
        bool match = false;
        while(i<j && j < n){
            if(s[i]==s[j]){
                match = true;
                longest = max(longest,j-i-1) ;
                i++;
                j=n-1;
            }
            else{
                j--;
                if(i==j){
                i++;
                j = n-1;
                }
            }
            
        }
        if(match) return longest;
       else return -1;
    }
};