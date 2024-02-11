class Solution {
public:

    bool topoSortBFS(int numCourses, unordered_map<int,list<int>>&adjList){
        queue<int>q;
        unordered_map<int,int>indegree;
        vector<int>ans;
        for(auto it : adjList){
             for(auto nbr : it.second){
                 indegree[nbr]++;
             }
        }
        // for(auto it : indegree){
        //     if(it.second==0){
        //         q.push(it.first);
        //     }
        // }

        for (int i=0; i<numCourses; i++) {
        if (indegree [i] == 0) {
        q.push(i) ;
        }
        }

        while(!q.empty()){
           int front =  q.front();
            ans.push_back(front);
           q.pop();
           for(auto nbr : adjList[front]){
               indegree[nbr]--;
               if(indegree[nbr] == 0){
                   q.push(nbr);
               }
           }
        }
        return (ans.size()==numCourses) ;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adjList;
        for(auto v : prerequisites){ // 
            adjList[v[1]].push_back(v[0]); //0->1 ; 1->0 (0 karne ke liye 1 course karna necessary)
        }
        return topoSortBFS(numCourses,adjList);
    }
};