class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        //last me ek one aana chahiye, baki ke ones front me
        int sz = s.size();
        int cnt = 0;
        for(char c : s){
            if(c=='1'){
                cnt++;
            }
        }
        string ans(s.size(),'0');
        // cout << cnt << endl;
        if(cnt>0){
            ans[sz-1] = '1';
            --cnt;
        }
        // cout << cnt << endl;
        int ind = 0;
        while(cnt>0){
            ans[ind] = '1';
            ind++;
            --cnt;
        }
        return ans;
    }
};