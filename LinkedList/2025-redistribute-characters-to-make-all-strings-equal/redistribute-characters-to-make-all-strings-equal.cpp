class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> m;
        for(string s : words){
            for(char ch : s){
                m[ch]++;
            }
        }
        int size = words.size();
        for(auto it : m){
            if(it.second%size!=0){
                return false;
            }
        }
        return true;
    }
};