class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int cnt = 0;
        bool fl = true;
        while(fl){
            for(int i = 0; i < tickets.size(); i++){
                if(i==k){
                    if(tickets[i]==0){
                        fl = false;
                        break;
                    }
                    else{
                        tickets[i]--;
                        cnt++;
                        if(tickets[i]==0){
                        fl = false;
                        break;
                        }
                    }
                }
                else if(tickets[i]>0){
                    tickets[i]--;
                    cnt++;
                }
            }
            // for(auto x : tickets){
            //     cout << x << " ";
            // }
            // cout<<"cnt val is: "<<cnt<<endl;
        }
        return cnt;
    }
};