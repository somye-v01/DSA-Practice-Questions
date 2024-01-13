class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> m;
        int cnt = 0;
        for(auto x : s){
           m[x]++; //leetcode : l-1,e-3,t-1,c-1,o-1,d-1
        } 
        
        for(auto x : t){
            if(m.find(x)==m.end() || m[x]==0){
                cnt++;
            }
            else{
                m[x]--;
            }
        }
        return cnt;
    }
};