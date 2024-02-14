class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        vector<int> positive;
        vector<int> neg;
        for(auto x : nums){
            if(x >= 0){
                positive.push_back(x);
            }
            else{
                neg.push_back(x);
            }
        }
        int i = 0;
        while(i<positive.size() && i < neg.size()){
            ans.push_back(positive[i]);
            ans.push_back(neg[i]);
            i++;
        }
        return ans;
    }
};