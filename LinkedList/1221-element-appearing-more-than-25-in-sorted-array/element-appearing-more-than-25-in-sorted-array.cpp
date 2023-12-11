class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int len = arr.size();
        unordered_map<int,int> m;
        for(int i = 0; i < arr.size();i++){
            m[arr[i]]++;
            if(m[arr[i]]>(len/4)){
                return arr[i];
            }
        }
        return 0;
    }
};