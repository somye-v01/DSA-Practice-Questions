class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        //har sum ke 2 copies hone chahiye, agar nahi h, to 
        unordered_set<int> se;
        for(string s : nums){
            //convert the string to int and put in set
            int stnum = stoi(s,0,2);
            se.insert(stnum);
        }
        int n = nums.size();
        string sans = "";
        for(int i = 0; i <= pow(2,n) - 1; i++){
            //convert this number to binary and check in set
            if(se.find(i) == se.end()){
                bitset<16>ans(i) ;
                sans = ans.to_string();
                break;
            }
        }
        return sans.substr(16-n,n);
    }
};