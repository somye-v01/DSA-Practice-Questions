class Solution {
public:

    bool valid(string s, int i){
        cout << i << endl;
        cout<<endl;
        unordered_map<char,int>m;
        string temp = s.substr(0,i);
        for(auto x : temp){
             m[x]++;
        }
        // for(auto x : m){
        //    cout << "in temp: "<<x.first << " -> " << x.second << endl;
        // }
        for(int j = i; j < s.size(); j=j+i){
            // cout << "size of str "<<s.size()<<endl;
            // cout << "val of i here is: "<<i<<endl;
            // cout << "val of j here is: "<<j<<endl;
            int k = i;
            int num = j;
            unordered_map<char,int>m2;
            while(k--){
                m2[s[j]]++;
                j++;
            }
            j = num;
            // for(auto x : m2){
            // cout << x.first << " -> " << x.second << endl;
            // }
            for(auto it : m2){
                if(m.find(it.first)==m.end() || it.second != m[it.first] ){
                    // cout << "entering here "<<endl;
                    return false;
                }
            }
        }
        return true;
    }

    int minAnagramLength(string s) {
        int n = s.length();
        for(int i = 1; i <= n; i++){
            if( (n%i==0) && valid(s,i)){
                return i;
            }
        }
        // cout << "entered";
    return n;
    }
};