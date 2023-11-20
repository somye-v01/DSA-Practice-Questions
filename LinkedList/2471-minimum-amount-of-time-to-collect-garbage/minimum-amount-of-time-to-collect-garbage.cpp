class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int lastM = 0;
        int lastP = 0;
        int lastG = 0;
        int totalcharcount = 0;
        int ans = 0;
        for(int i = 0; i < garbage.size(); i++){
            for(char ch : garbage[i]){
                if(ch == 'M'){
                    lastM = i;
                }
                else if(ch == 'G'){
                    lastG = i;
                }
                else{
                    lastP = i;
                }
                totalcharcount++;
            }
        }
        //prefix sum the travel array
        for(int i = 1; i < travel.size() ;i++){
            travel[i] += travel[i-1];
        }
        if(lastP > 0 ){
            ans+=travel[lastP - 1];
        }
        if(lastG > 0 ){
            ans+=travel[lastG - 1];
        }
        if(lastM > 0){
            ans+=travel[lastM - 1];
        }
        return ans+totalcharcount;
    }
};