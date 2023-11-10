class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
    //     priority_queue<int> pq;
    //     for(string s : nums){
    //         pq.push(stoi(s));
    //     }
    //     if(k == 1) return to_string(pq.top());
    //    for(int i = 0; i < k - 1; i++){
    //        pq.pop();
    //    }
    //    int ans = pq.top();
    //    string sol = to_string(ans);
    //    return sol;
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
        for(auto elem : nums)
        {
            pq.push({elem.size(),elem});
             if(pq.size()>k)
             {
                 pq.pop();
             }
        }
         return pq.top().second;
    }
};