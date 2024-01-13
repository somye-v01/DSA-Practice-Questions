class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> m;
        // unordered_map<char,int> m2;
        int cnt = 0;
        for(auto x : s){
           m[x]++; //leetcode : l-1,e-3,t-1,c-1,o-1,d-1
        } 
        // for(auto x : t){
        //     m2[x]++; //practice : p-1,r-1,a-1,c-2,t-1,i-1,c-1,e-1
        // // }
        // for(auto x : s){
        //     if(m2.find(x)==m2.end()){
        //         cnt+=m[x];
        //     }
        // }
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