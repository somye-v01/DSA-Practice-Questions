class Solution {
public:
    int maxScore(string s) {
       
        int first0 = 0;
        int first1 = 0;
        vector<int> Index0s;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='0'){
                Index0s.push_back(i);
            }
        }
        for(auto x : Index0s){
            cout << x << " ";
        }
    int max0sand1s = 0;
    int counttemp = 0;
    for(int i = 0; i < s.size();i++){
        if(s[i]=='0'){
            counttemp++;
            max0sand1s = max(max0sand1s,counttemp-1);
        }
        if(s[i]=='1'){
            // max0sand1s = max(max0sand1s,counttemp);
            counttemp=0;
        }
    }
    counttemp = 0;
    for(int i = 0; i < s.size();i++){
        if(s[i]=='1'){
            counttemp++;
            max0sand1s = max(max0sand1s,counttemp-1);
        }
        if(s[i]=='0'){
            // max0sand1s = max(max0sand1s,counttemp);
            counttemp=0;
        }
    }
    int temp1 = 0;
    int temp2 = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='0'){
            temp1++;
        }
        if(s[i]=='1'){
            temp2++;
        }
    }
    max0sand1s = max(max0sand1s,max(temp1-1,temp2-1));
        for(auto x : Index0s){
            int max0s = 0;
            int max1s = 0;
            for(int i = 0; i < s.size(); i++){
                if(i<=x && s[i]=='0'){
                    max0s++;
                }
                if(i>x && s[i]=='1'){
                    max1s++;
                }
            }
            if(max1s==0){
                max0sand1s = max(max0sand1s,max0s-1 );
            }
            else{
            max0sand1s = max(max0sand1s,max1s+max0s );
            }
        }
        return max0sand1s;
    }
};