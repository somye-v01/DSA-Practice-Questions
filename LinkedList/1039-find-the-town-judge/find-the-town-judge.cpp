class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>m;
        unordered_map<int,int>cnt;
        for(auto x : trust){
            // int sec = 
            m[x[0]] = x[1];
            cnt[x[1]]++;
        }
        for(int i = 1; i <= n; i++){
            if(m.find(i)==m.end() && cnt[i]==n-1){
                return i;
            }
            // if(cnt[i]<n-1){
            //     return i;
            // }
        }
        return -1;
    }
};