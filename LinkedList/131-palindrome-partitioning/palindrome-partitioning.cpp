class Solution {
public:

    bool checkPalindrome(string s, int i, int j){
        // int n = s.size()-1;
        // int i = 0;
        while( i <= j ){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void solve(string& s, int i,vector<string>&temp, vector<vector<string>>& ans ){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        //include
        for(int j = i ; j < s.size(); j++){
            if(checkPalindrome(s,i,j)){
                temp.push_back(s.substr(i,j-i+1));
                solve(s,j+1,temp,ans);
                temp.pop_back();
            }
        }
        //dont include

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>temp;
        solve(s,0,temp,ans);
        return ans;
    }
};