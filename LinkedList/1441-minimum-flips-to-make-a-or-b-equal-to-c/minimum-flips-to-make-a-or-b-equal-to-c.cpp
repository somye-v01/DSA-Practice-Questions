class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<32>cbit(c),abit(a),bbit(b);
        int cnt = 0;
        for(int i = 0; i < 32; i++){
            int bit = cbit[i];
            if((abit[i]|bbit[i]) != bit){
                if(bit==0 && (abit[i]==1 && bbit[i]==1)){
                    cnt+=2;
                }
                // else if(bit==1 && (abit[i]==0 && bbit[i]==0)){
                //     cnt+=2;
                // }
                else{
                    cnt+=1;
                }
            }
        }
        return cnt;
    }
};