class Solution {
public:

    int helper(string& s, int i, int j){
        if(i>=j) return 1;
        if(s[i]!=s[j]) return 0;
        return helper(s,i+1,j-1);
    }

    int solve(string& s, int i){
        if(i>=s.size()) return 0;
        //include
        int count = 0;
        for(int j = i; j < s.size(); j++){
            count+=helper(s,i,j);
        }
        count += solve(s,i+1);
        return count;
    }

    int countSubstrings(string s) {
        return solve(s,0);
    }
};