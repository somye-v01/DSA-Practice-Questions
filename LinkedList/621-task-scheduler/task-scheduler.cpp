class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        char maxch = 'A';
        int cnt = 0;
        int c=0;
        // unordered_map<char,int>m;
        for(auto t : tasks){

            // m[t]++;
           freq[t-'A']++;
           int temp = cnt;
           cnt  = max(cnt,freq[t-'A']);
            if(cnt!=temp){
                c=0;
                maxch = t;
            }
            if(freq[t-'A']==cnt) c++;
        }
        int x = ((cnt-1)*(n+1))+c;
        return x>tasks.size()?x:tasks.size();
        
        // for(int i = 0; i < 26; i++){
        //     m['A'+ i ]=freq[i];
        // }
        // // for(auto x : m){
        //     cout<<x.first << " " << x.second << endl;
        // }
        // map<int,char>m2;
        // priority_queue<pair<int,char>>pq;
        // for(int i = 0; i < 26; i++){
        //     if(freq[i]>0){
        //         pq.push({freq[i], (char)i+'A'});
        //     }
        // }
        // while(!pq.empty()){
        //     auto x = pq.top();
        //     cout << x.first << "->" << x.second << endl;
        //     pq.pop();
        // }
        // cout << maxch << endl;

        return 0;
    }
};