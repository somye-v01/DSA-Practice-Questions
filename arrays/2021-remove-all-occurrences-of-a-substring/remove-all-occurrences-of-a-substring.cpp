class Solution {
public:
    string removeOccurrences(string s, string part) {
        int ans = s.find(part);
        //BaseCase
        if(ans!=string::npos){
        //ek case solve kr do
        string left_str = s.substr(0,ans);
        string right_str = s.substr(ans+part.length(),s.length());
        s = left_str + right_str;
        return removeOccurrences(s,part);
        }
        else{
            return s;
        }
        
    }
};