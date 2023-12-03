class Solution {
public:
    string interpret(string command) {
        string ans = "";
        for(int i = 0; i < command.size(); i++){
            if(command[i]=='G'){
                ans.push_back('G');
            }
            if(command[i]=='(' && command[i+1] == ')' ){
                ans.push_back('o');
            }
            if(command[i]=='(' && command[i+1] == 'a' ){
                ans+="al";
            }
        }
        return ans;
        
    }
};