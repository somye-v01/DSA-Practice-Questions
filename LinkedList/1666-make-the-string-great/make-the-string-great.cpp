class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            
            if(st.size()>0 && isupper(st.top()) && islower(c) && (c-32 == st.top() )) {
                st.pop();
                continue;
            }
            if(st.size()>0 && islower(st.top()) && isupper(c) && (c+32 == st.top())) {
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};