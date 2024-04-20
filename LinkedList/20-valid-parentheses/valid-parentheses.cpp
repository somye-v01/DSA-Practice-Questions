class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto ch : s){
            if (!st.empty() && ((st.top() == '(' && ch == ')') || (st.top() == '[' && ch == ']') || (st.top() == '{' && ch == '}'))) {
                st.pop();
                continue;
            }
            // else{
            st.push(ch);
            // }
        }
        return st.empty();
    }
};