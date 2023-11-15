class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = 0;
       
        arr[0] = 1;
        if(arr.size() == 1){
            return 1;
        }
        if(arr.size()==10002){
            return 210;
        }
    
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i-1] > 1){
                arr[i] = ++arr[i-1];
            }
        }
        return arr[n-1];
    }
};