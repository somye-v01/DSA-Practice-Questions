class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //sort
        //last + first try
        //if success, try 2nd last
        sort(people.begin(),people.end());
        int i = 0;
        int n = people.size()-1;
        int cnt = 0;
        int sum = 0;
        while(n>=0 && sum <= limit && i <= n){
            sum+=people[n];
            if(n-1>=0 && sum+people[n-1]<=limit){
                cnt++;
                n-=2;
                sum=0;
                continue;
            }
            else if(i!=n && sum+people[i]<=limit){
                cnt++;
                i+=1;
                n-=1;
                sum=0;
                continue;
            }
            else{
                cnt++;
                sum=0;
                n--;
            }
        }
        return cnt;
    }
};