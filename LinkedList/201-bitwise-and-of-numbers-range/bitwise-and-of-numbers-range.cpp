class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
       
        bitset<32>l(left);
        bitset<32>r(right);
        bitset<32>f(0);
        for(int i = 31; i>=0; i--){
            // if(r[i]!=l[i]) break;
            if(r[i]==l[i]){
                f[i] = r[i];
            }
            else{
                break;
            }
        }
        // cout << f.to_string();
        return f.to_ulong();

        // // if( right > (2*left)-1){
        // //     return 0;
        // // }
        // bitset<32> bin(left);
        // string str = bin.to_string() ;
        // // cout << str << endl;
        // int temp = 0;
        // int count = 0;
        // int sum = 0;
        // if(left==right) return left;

        // for(int i = 0; i < str.size(); i++){
        //     if(str[i]=='1'){
        //         temp = str.size()-i;
        //         while(i<str.size() && str[i]!='0'){
        //             int temp2 = str.size()-i;
        //             sum+=pow(2,(temp2-1));
        //             i++;
        //         }
        //         break;
        //     }
        // }
        // int minval = pow(2,(temp-1));
        // cout << minval ;
        // if(right > (2*minval)-1) return 0;
        // return sum;
    }
};