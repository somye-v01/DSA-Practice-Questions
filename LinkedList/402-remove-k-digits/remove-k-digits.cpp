class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string result = ""; //it will act like a stack
        int n = num.length();
        
        for(int i = 0; i < n; i++) {
            
            while(result.length() > 0 && result.back() > num[i] && k > 0) {
                result.pop_back();
                k--;
            }
            
            if(result.length() > 0 || num[i] != '0') {
                result.push_back(num[i]); //to avoid the case when we have preceeding zeros
            }
            
        }
    
        while(result.length() > 0 && k > 0) {
            result.pop_back();
            k--;
        }

        if(result == "") {
            return "0";
        }
        
        return result;
        
    }
};


// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         // int nums = num - '0';
//         int n = num.size();
//         if(k>=n) return "0";
//         stack<int>s;
//         bool fl = false;
//         for(int i = 0; i < n ; i++){
//             // if(i==n-1) fl = true;
//             // cout<<"pushing "<<num[i]-'0'<<" into stack"<<endl;
//             s.push(num[i]-'0');
//             if( k>0 && !s.empty() && num[i]-'0' > num[i+1] - '0' ){
//                 // cout<<"popping "<<s.top()<<" from stack"<<endl;
//                 s.pop();
//                 k--;
//             }
//             // if(k==0){
//             //     s.push(num[i] - '0');
//             // }
//         }
//         int lastin = n-1;
//         while( k-- ){
//             // cout<<"value of k here is: "<<k<<endl;
//             s.pop();
//             lastin--;
//         }
//         string ans = "";
//         while(!s.empty()){
//             ans.push_back(s.top()+'0');
//             s.pop();
//         }
//         reverse(ans.begin(),ans.end());
//         while(ans.front()=='0'){
//             ans.erase(ans.begin());
//         }
//         return (ans.size()>0) ? ans : "0" ;
//     }
// };