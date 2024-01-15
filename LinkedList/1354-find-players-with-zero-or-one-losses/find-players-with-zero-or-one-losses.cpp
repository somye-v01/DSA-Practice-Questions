class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> losers;
        set<int> s;
        vector<vector<int>> ans(2);
        
        for (vector<int> match : matches){
            losers[match[1]]++;
        }
        for(auto x : matches){
            if(losers.find(x[0]) == losers.end()){
             s.insert(x[0]);
            }
        }
            for(auto i : s){
                ans[0].push_back(i);
            }
             s.clear();
            for(auto x : matches){
            if(losers.find(x[1]) != losers.end()){
                if(losers[x[1]]==1){
                    s.insert(x[1]);
                }
            }
        }
            for(auto i : s){
                ans[1].push_back(i);
            }
        return ans;
    }
};