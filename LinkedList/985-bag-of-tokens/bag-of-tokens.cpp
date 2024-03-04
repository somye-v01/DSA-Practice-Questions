class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //find the min bag -> score 1
        //find the max bag ensuring leftover tokens size>1, add it to power -> score 0
        //while score>0 -> find min bag, increase score by 1.
        //if power<=min(tokens),do step 2 again.
        int score = 0;
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int i = 0;
        int j = n-1;
        while(i <= j){
            if(tokens[i]<=power){
                power-=tokens[i];
                score++;
                i++;
            }
            else if(score>=1 && power<tokens[i] && j-i>=1){
                power+=tokens[j];
                score--;
                j--;
            }
            else{
                break;
            }
        }
        return score;
    }
};