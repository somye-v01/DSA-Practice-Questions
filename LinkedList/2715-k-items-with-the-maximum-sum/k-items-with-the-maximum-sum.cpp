class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        // vector<int> v;
        // for(int i = 0; i < numOnes; i++){
        //     v.push_back(1);
        // }
        // for(int i = 0; i < numZeros; i++){
        //     v.push_back(0);
        // }
        // for(int i = 0; i < numNegOnes; i++){
        //     v.push_back(-1);
        // }
        // for(auto x : v){
        //     cout << x << " ";
        // }
        // return 0;
        int ans = 0;
        if(k>0){
            if(numOnes>=k){
                ans=k;
                k = 0;
            }
            else{
                ans=numOnes;
                k = k - numOnes;
            }
        }
        if(k>0){
            if(numZeros>=k){
                
                k = 0;
            }
            else{
               
                k = k - numZeros;
            }
        }
        if(k>0){
            if(numNegOnes>=k){
                ans = ans - k;
                k = 0;
            }
            else{
                ans-=numNegOnes;
                k = k - numNegOnes;
            }
        }
        return ans;
    }
};