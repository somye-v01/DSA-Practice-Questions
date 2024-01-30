class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        unordered_set<string>s = {"+","-","*","/"};
        // s.insert('+');
        // s.insert('-');
        // s.insert('*');
        // s.insert('/');
        int ans = 0;
        for(int i = 0; i < tokens.size(); i++){
            if(s.find(tokens[i])==s.end()){ //it is a number 
                ans = stoi(tokens[i]);
                st.push(tokens[i]);
            }
            else{
                //it is a operant
                int num1 = stoi(st.top());
                st.pop();
                int num2 = stoi(st.top());
                st.pop();
                if(tokens[i]=="+"){
                    int numtopush = num1+num2;
                    ans=numtopush;
                    st.push(to_string(numtopush));
                }
                else if(tokens[i]=="-"){
                    int numtopush = num2-num1;
                    ans=numtopush;
                    st.push(to_string(numtopush));
                }
                else if(tokens[i]=="*"){
                    int numtopush = num1*num2;
                    ans=numtopush;
                    st.push(to_string(numtopush));
                }
                else if(tokens[i]=="/"){
                    int numtopush = num2/num1;
                    ans=numtopush;
                    st.push(to_string(numtopush));
                }
            }
        }
        return ans;
    }
};