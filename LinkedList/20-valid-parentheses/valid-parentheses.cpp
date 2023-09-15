class Solution {
public:
    bool isValid(string s) {
        //every opening bracket ke liye ek closing bracket hona chahiye after it.
        stack<char> se;
        for (auto x : s){
            //opening brackets
            if (x == '(' || x == '{' || x == '['){
                se.push(x);
            }
           
            //closing brackets
            
            else{
                if(se.empty()){
                    return false;
                }
                char topch = se.top();
                if ((x == ')' && topch == '(') ||(x == '}' && topch == '{') || (x == ']' && topch == '[')){
                    se.pop();
                }
                else{
                    return false;
                }
            }
                    
        }
        if (se.empty() == true){
            return true;
        }
        else{
            return false;
        }
        
        
    }
};