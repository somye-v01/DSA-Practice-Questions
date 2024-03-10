class Solution {
public:

    static bool compareLength(string& a, string& b){
        if(a.size()==b.size()){
            return a<b;
        }
        return a.size()<b.size();
    }

    vector<string> shortestSubstrings(vector<string>& arr) {
        unordered_map<string,int>m;
        vector<string> ans(arr.size());
        for(auto x : arr){
            unordered_set<string>se;
            for(int i = 0; i < x.size(); i++){
                // int cnt = x.size();
                // while(x.size()-i-cnt!=0)
               for (int j = i; j < x.size(); j++) {
                    string st = x.substr(i,j - i + 1);
                    if(se.find(st)==se.end()){
                        se.insert(st);
                        m[st]++;
                    }
                }
                // for(int j = i; j < x.size() ;j++){

                // }
            }
            

        }
        // for(auto x : m){
        //     cout << x.first << " -> "<<x.second<<endl;
        // }
        int ind = 0;
        for(auto x : arr){
            //generate all the substrings
            //put it in a vector
            //sort the vector - put custom comp
            //find the 1st string jiska count-1==0 ho, put that in ans vector.
            //break and go to next word in the vector
            vector<string>temp;
            for(int i = 0; i < x.size(); i++){
                for (int j = i; j < x.size(); j++) {
                    string st = x.substr(i, j - i + 1);
                    if(m[st]==1){
                    temp.push_back(st);
                    }
                
                }
                // for(auto s : temp){
                //     cout << s << " ";
                //     cout<<endl;
                // }
                
            }
            //  for(auto s : temp){
            //         cout << s << " ";
            //         cout<<endl;
            //     }
            sort(temp.begin(),temp.end(),compareLength);
            if(temp.size()>=1){
            ans[ind] = temp[0];
            }
            ind++;

        }
        return ans;
    }
};