class Solution {
public:
    int tribonacci(int n) {
        vector<int>a(n+1,0);
        if(n==0) return 0;
        if(n<=2) return 1;
        a[1] = 1;
        a[2] = 1;
        //have to do for n = 3 too.
        for(int i = 3; i <= n; i++){
            a[i] = a[i-3] + a[i-2] + a[i-1];
        }
        return a[n];
    }
};