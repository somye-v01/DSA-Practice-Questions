class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int>ans(deck.size(),0);
        sort(deck.begin(),deck.end());
        int n = deck.size();
        int i = 0;
        int j = 0;
        int last = 0;
        while(j < n){
            ans[j] = deck[i];
            i++;
            last = j;
            j=(j+2);
            // if()
        }
        j = last;
        int cnt =0;
        while(i < n){
            if(ans[j]==0) cnt++;
            if(cnt==2) {
                cnt = 0;
                ans[j] = deck[i];
                i++;
                continue;
            }
            else{
                // if(j+1==n)
                j++;
                if(j==n){
                    j=0;
                }
            }
            
        }
        // for(auto x : ans){
        //     cout << x << " ";
        // }
        return ans;
    }
};