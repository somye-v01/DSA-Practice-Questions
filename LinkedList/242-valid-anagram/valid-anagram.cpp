class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;

        for(auto x : s){
            m1[x]++;
        }
        for(auto x : t){
            m2[x]++;
        }
         if (m1.size() != m2.size()) {
            return false;
        }
            for (auto& x : m1){
                if ((m2.find(x.first) == m2.end()) || (m2[x.first] != x.second)){
                    return false;
                }
               
            }
        
        return true;
    }
};