class Solution {
public:
 int give1scount(int num){
            if(num == 0){
                return 0;
            }
            int count =0;
            while(num > 0){
                if(num%2==0){
                    
                    num=num/2;
                }
                else{
                    count++;
                    num = num/2;
                }
            }
            return count;
        }
    vector<int> sortByBits(vector<int>& arr) {
        // multimap<int,int>m;
        vector<pair<int,int>> v;
       for(int i = 0; i < arr.size();i++){
        //    m[ give1scount(arr[i]) ] =arr[i] ;
        // m.insert(make_pair(give1scount(arr[i]), arr[i]));
        // m.emplace(give1scount(arr[i]), arr[i]);
        v.push_back({give1scount(arr[i]) , arr[i]});
       }
       sort(v.begin(),v.end());
       vector<int> ans;
       for(auto x : v){
           ans.push_back(x.second);
       }
       return ans;
    }
};