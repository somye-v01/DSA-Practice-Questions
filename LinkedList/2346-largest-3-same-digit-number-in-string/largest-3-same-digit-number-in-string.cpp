class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        vector<char> ans;
        for(int i = 0; i < n-2; i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                ans.push_back( num[i] );
            }
        }
        int maxn = -1;
        for(auto x : ans){
            maxn = max(maxn, x-'0');
        }
        if (maxn == -1) return "";
        string str = "";
        str.push_back(maxn + '0');
        str.push_back(maxn + '0');
        str.push_back(maxn + '0');
        return str;
    }
};