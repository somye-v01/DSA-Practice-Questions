class Solution {
public:
    bool isPowerOfTwo(int n) {
        int temp = 1;
        for(int i = 0; i < 31; i++){
            if(temp==n){
                return true;
            }
            if(temp<INT_MAX/2){
                temp=temp*2;
            }
        }
        return false;
    }
};