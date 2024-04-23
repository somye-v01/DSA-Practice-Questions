class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> indegree(n,0);
        unordered_map<int,vector<int>>m;
        for(auto edge : edges){
            indegree[edge[0]]++;
            indegree[edge[1]]++;
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }
        vector<int>res;
        queue<int>q;
        for(int i = 0; i < n; i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        while(n>2){
            int sz = q.size();
            n-=sz;
            while(sz--){
                int u = q.front();
                q.pop();
                for(int &v : m[u] ){
                    indegree[v]--;
                    if( indegree[v] == 1) {
                    q.push(v);
                    }
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};