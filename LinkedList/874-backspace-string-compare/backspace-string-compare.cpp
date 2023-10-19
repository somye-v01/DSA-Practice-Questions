class Solution {
public:
    bool backspaceCompare(string s, string t) {
    stack<char> s1;
    stack<char> s2;
    for(char ch : s){
        if(!s1.empty() && ch == '#'){
            s1.pop();
        }
        else{
            if(isalpha(ch)){
            s1.push(ch);
            }
        }
    }
    for(char ch : t){
        if(!s2.empty() && ch == '#'){
            s2.pop();
        }
        else{
            if(isalpha(ch)){
            s2.push(ch);
            }
           
        }
    }
    string res1;
    string res2;
    while(!s1.empty()){
        char c = s1.top();
        res1+=c;
        s1.pop();
    }
    while(!s2.empty()){
        char c = s2.top();
        res2+=c;
        s2.pop();
    }
    return (res1==res2);
    }
};