class Solution {
public:
    
    // bool static comp(char &a, char &b){
    //     return m[a]>m[b];
    // }

    string frequencySort(string s) {
        string ans;
        unordered_map<char,int> m;
        // map<int,char>m1;
        for(auto x : s){
            m[x]++;
        }
        sort(s.begin(),s.end(),[&](char &a, char &b){
            if(m[a]==m[b]) return b>a;
            return m[a]>m[b];
        });
        return s;
    }
};