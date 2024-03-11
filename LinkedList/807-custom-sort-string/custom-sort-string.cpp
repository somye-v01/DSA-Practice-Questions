class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        unordered_map<char,int>m;
        for(auto ch : s){
            m[ch]++;
        }
        for(auto ch : order){
            if(m.find(ch)!=m.end()){
                while(m[ch]!=0){
                    ans.push_back(ch);
                    m[ch]--;
                }
            }
        }
        for(auto it : m){
            if(it.second!=0){
                while(it.second!=0){
                    ans.push_back(it.first);
                    --it.second;
                }
            }
        }
        return ans;
    }
};