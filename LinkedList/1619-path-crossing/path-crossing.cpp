class Solution {
public:
    bool isPathCrossing(string path) {
        //n 1,s -1, e -.5, w -0.5
        int res = 0;
        unordered_set<int> s;
        for(int i = 0; i < path.size(); i++){
            if(path[i]=='N'){
                res++;
                if(s.find(res)!=s.end() || (res==0&&i>0) ){
                    return true;
                    break;
                }
                s.insert(res);
                // if(res==0 && i>0 ){
                //     return true;
                // }
            }
            if(path[i]=='S'){
                res--;
                if(s.find(res)!=s.end() || (res==0&&i>0)){
                    return true;
                    break;
                }
                s.insert(res);
                // if(res==0 && i>0 ){
                //     return true;
                // }
            }
            if(path[i]=='E'){
                res=res+100;
                if(s.find(res)!=s.end() || (res==0&&i>0)){
                    return true;
                    break;
                }
                s.insert(res);
                // if(res==0 && i>0 ){
                //     return true;
                // }
            }
            if(path[i]=='W'){
                res=res-100;
                if(s.find(res)!=s.end() || (res==0&&i>0)){
                    return true;
                    break;
                }
                s.insert(res);
                // if(res==0 && i>0 ){
                //     return true;
                // }
            }
        }

        return false;
    }
};