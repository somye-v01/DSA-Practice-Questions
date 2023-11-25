class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool match = true;
        string ans = "";
        for(int i = 0; i < strs[0].size(); i++){
            for(int j = 1; j < strs.size(); j++){
                if(strs[j].size() < i || strs[0][i] != strs[j][i]){
                    match = false;
                    break;
                }
            }
            if(match == true){
                ans.push_back(strs[0][i]);
            }
            else{
                break;
            }
        }
        return ans;
    }
};