class Solution {
public:
    int firstUniqChar(string s) {
        // unordered_map<int,int>m;
        vector<int> cnt(26,0);
        for(int i = 0; i < s.size(); i++){
            cnt[s[i]-'a']++;
            }
        
        // int temp = 1;
       
        for(int i = 0; i < s.size(); i++){
            if(cnt[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};