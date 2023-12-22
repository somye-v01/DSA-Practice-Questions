class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last = digits[digits.size()-1];
        if(last<9){
            digits[digits.size()-1] = digits[digits.size()-1]+1;
        }
        else{
            digits[digits.size()-1] = 0;
            // digits.insert(digits.begin()+(digits.size()-2),1);
            for(int i = digits.size()-2; i >= 0; i--){
                if(digits[i]<9){
                    digits[i]=digits[i]+1;
                    break;
                }
                else{
                    digits[i]=0;
                }
            }
            if(digits[0]==0){
                digits.insert(digits.begin(),1);
            }
        }
        return digits;
    }
};