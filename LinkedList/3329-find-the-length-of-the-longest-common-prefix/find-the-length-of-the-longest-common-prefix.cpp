class Solution {
public:

    int getlen(int num){
        int cnt = 0;
        while(num!=0){
            cnt++;
            num/=10;
        }
        return cnt;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>s;
        for(auto it : arr1){ //105
            while(it>0){
                s.insert(it);
                it=it/10;
            }
        }
        int maxi = 0;
        for(auto it : arr2){
            while(it>0){
                if(s.find(it)!=s.end()){
                    maxi = max(maxi,getlen(it));
                    
                }
                it/=10;
            }
        }
        return maxi;
    }
};