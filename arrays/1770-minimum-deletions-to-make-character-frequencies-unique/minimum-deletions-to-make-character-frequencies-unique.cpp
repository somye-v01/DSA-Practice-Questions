class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq;
        map<char,int> m;
        for(auto x : s){
            m[x]++;
        }
        for(auto x : m){
            freq.push_back(x.second);
        }
        for(auto x : freq){
            cout<<x<<" ";
        }
        int count = 0;
        sort(freq.begin(),freq.end());
        set<int> se;
        for(int i = 0; i<freq.size(); i++){
            while(se.find(freq[i])!=se.end() && freq[i]!=0){
                --freq[i];
                count++;
            }
            se.insert(freq[i]);
        }
        return count;
    }
};