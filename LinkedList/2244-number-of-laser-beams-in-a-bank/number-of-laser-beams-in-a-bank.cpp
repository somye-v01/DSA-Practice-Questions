class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> noOf1s;
        for(int i = 0; i < bank.size(); i++){
            int count = 0;
            for(int j = 0; j < bank[i].size(); j++){
                if(bank[i][j]=='1'){
                    count++;
                }
            }
            if(count!=0){
            noOf1s.push_back(count);
            }
        }
        int ans = 0;
        for(auto x : noOf1s){
            cout << x << " ";
        }
        for(int i = 1; i < noOf1s.size(); i++){
            ans += noOf1s[i]*noOf1s[i-1];
        }
        return ans;
    }
};