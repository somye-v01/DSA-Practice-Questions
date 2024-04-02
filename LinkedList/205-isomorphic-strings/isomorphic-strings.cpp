class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int>temp1(256,0);
        vector<int>temp2(256,0);
        for(int i = 0; i < s.size(); i++){
            if(temp1[s[i]]!=temp2[t[i]]) return false;
            temp1[s[i]] = i+1;
            temp2[t[i]]=i+1;
        }
        return true;
    }
};