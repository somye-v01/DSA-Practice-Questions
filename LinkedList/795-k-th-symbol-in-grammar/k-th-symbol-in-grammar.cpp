class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 && k==1){
            return 0;
        }
        int mid = pow(2,n-1)/2;
        if(k <= mid){
            return kthGrammar(n-1,k);//upar wala hi kth index iska bhi hoga
        }
        else{
            return 1 - kthGrammar(n-1,k-mid);
        }
        
    }
};

     /*
        0
        01
        0110
        01101001
        
        */
        // string s = "0";
        // if (n==1) return 0;
        // for(int i = 2; i <=n; i++){
        //   string temp;
        //     for(int j = 0; j < s.size();j++){
        //         if(s[j]=='0'){
        //            temp+="01";
        //         }
        //         else{
        //             temp+="10";
        //         }
        //     }
        //     s = temp;
        // }
        // return s[k-1]-'0';