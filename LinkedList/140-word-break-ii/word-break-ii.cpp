class Solution {
public:

    vector<string> solve(string s, unordered_set<string>&st, int i){
        if(i>=s.size()){
            return {""};
        }
        vector<string>ans;
        string word = "";
        for(int j = i; j < s.size(); j++){
            word+=s[j];
            if(st.find(word)==st.end()){
                continue;
            }
            //agar word mil gya he to
            auto right_answer = solve(s,st,j+1);
            for(auto str : right_answer){
                string toput;
                if(str.size()!=0){
                    toput = " " + str;
                }
                ans.push_back(word+toput);
            }
            // ans.push_back(word);
            
        }
        return ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto str : wordDict){
            st.insert(str);
        }
        return solve(s,st,0);
    }
};