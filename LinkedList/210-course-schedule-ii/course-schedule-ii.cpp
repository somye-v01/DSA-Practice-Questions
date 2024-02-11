class Solution {
public:

    vector<int> topoSortBfs(int n, unordered_map<int,list<int>>&adjList){
        vector<int>ans;
        unordered_map<int,int>indegree;
        queue<int>q;
        for(auto it : adjList){
            for(auto el : it.second){
            indegree[el]++;
            }
        }
        for(int i = 0; i < n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front  = q.front();
            ans.push_back(front);
            q.pop();
            for(auto nbr : adjList[front]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        // return (ans.size()==n) ? ans : vector<int>(0);
        if(ans.size()==n){
            return ans;
        }
        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adjList;
        for(auto v : prerequisites){
            adjList[v[1]].push_back(v[0]);
        }
        return topoSortBfs(numCourses, adjList);
    }
};