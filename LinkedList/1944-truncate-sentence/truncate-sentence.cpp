class Solution {
public:
    string truncateSentence(string s, int k) {
        vector<string> words;
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            temp+=s[i];
            if(s[i]==' '){
                words.push_back(temp);
                temp = "";
            }
        }
        string ans = "";
        if(k>words.size()) return s;
        for(int i = 0; i < k; i++){
            ans+=words[i];
            // ans+=' ';
        }
        if (!ans.empty()) {
            ans.pop_back();
           
        }
    return ans;
    }
};