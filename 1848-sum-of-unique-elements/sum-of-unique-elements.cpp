class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> m;
        unordered_set<int> s;
        for (auto x : nums){
            m[x]++;
            
        }
        for (auto& x : m){
            s.insert(x.first);
            if (x.second > 1){
            s.erase(x.first);
            }
        }
        int sum = 0;
        for (auto& x : s){
            sum += x;
        }
        return sum;
    }

};