class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans;
        // int bits = ;
        bitset<10>bits(n);
        string str = bits.to_string();
        int size = str.size();
        int odd = 0;
        int even = 0;
        for(int i = 0; i < size; i++){
            if(str[i] == '1'){
                if(i%2){
                    even++;
                }
                else{
                    odd++;
                }
            }
        }
        return {even,odd};

    }
};