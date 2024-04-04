class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int si = 0;
        for(char ch : s){
            if(ch=='('){
                st.push('(');
                int stacksize = st.size();
                si = max(si,stacksize);
            }
            if(st.size()>0 && ch==')'){
                st.pop();
            }
        }
        return si;
    }
};