class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        int index = 0;
        if(ruleKey == "type"){
            index = 0;
        }
        else if(ruleKey == "color"){
            index = 1;
        }
        else{
            index = 2;
        }
        for(auto v : items){
            
                if(v[index] == ruleValue){
                    count++;
                 
                }
            
        }
        return count;
    }
};