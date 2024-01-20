class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> s1;
        stack<int> s2;
        int n = arr.size();
        vector<int> nextsmall(n);
        vector<int> prevsmall(n);
        for(int i = 0; i < n; i++){ // DEFAULT CASE WHEN THERE IS NO NEXT/PREV SMALL, ITS STRICLY INCREASING/DECREASING
        nextsmall[i] = n - i -1; // say 35789 and arr[i] at 5,no next smaller, so nextsmaller[1] = 5(size) - 1 - 1, so nextsmaller for 5 is 3 distances away.
        prevsmall[i] = i; 
        }
        for(int i = 0; i < n; i++){
            //next small
            while(!s1.empty() && arr[s1.top() ] > arr[i]){
                nextsmall[s1.top()]= i-s1.top()-1;
                s1.pop();
               
            }
              s1.push(i);     
        }
            //prev small
        for (int i = n - 1; i >= 0; --i) {
        while (!s2.empty() && arr[s2.top()] >= arr[i]) {
                prevsmall[s2.top()] = s2.top() -  i - 1;
                s2.pop();
                }
            s2.push(i);
        }
        long long ans = 0;
        const int MOD = 1e9+7;
        for(int i = 0; i < n; i++){
             ans+= arr[i] *(long long)( prevsmall[i] + 1) * (nextsmall[i] + 1) ;
        } 
        ans%=MOD;
        return ans;
    }
};


// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int n = arr.size();
//         std::vector<int> nextsmall(n, -1);
//         std::vector<int> prevsmall(n, -1);
//         std::stack<int> s1; // Stack to store indices of elements

//         // Initialize nextsmall and prevsmall
//         for (int i = 0; i < n; i++) {
//             while (!s1.empty() && arr[s1.top()] > arr[i]) {
//                 s1.pop();
//             }
//             if (!s1.empty()) {
//                 prevsmall[i] = s1.top();
//             }
//             s1.push(i);
//         }

//         // Clear the stack for the next round
//         while (!s1.empty()) {
//             s1.pop();
//         }

//         for (int i = n - 1; i >= 0; i--) {
//             while (!s1.empty() && arr[s1.top()] > arr[i]) {
//                 s1.pop();
//             }
//             if (!s1.empty()) {
//                 nextsmall[i] = s1.top();
//             }
//             s1.push(i);
//         }

//         int ans = 0;
//         const int MOD = 1e9 + 7;

//         for (int i = 0; i < n; i++) {
//             ans = (ans + (long long)arr[i] * (i - prevsmall[i]) * (nextsmall[i] - i)) % MOD;
//         }

//         return ans;
//     }
// };
