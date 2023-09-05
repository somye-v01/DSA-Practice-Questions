// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         map<int,int> m;
//         vector<int> ans;
//         for(int i = 0; i < nums.size(); i++){
//             m[nums[i] * nums[i]]++;
//         }
//         for (auto& x : m){
//             if (x.second == 1){
//             ans.push_back(x.first);
//             }
//             while(x.second != 1 && x.second > 0){
//                 ans.push_back(x.first);
//                 --x.second;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        map<int, int> m;
        vector<int> ans;

        for (int num : nums) {
            int squared = num * num;
            m[squared]++;
        }

        
        for (auto& x : m) {
            for (int i = 0; i < x.second; i++) {
                ans.push_back(x.first);
            }
        }

        return ans;
    }
};
