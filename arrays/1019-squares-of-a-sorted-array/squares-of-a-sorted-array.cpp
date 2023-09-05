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

        // Square each element and count occurrences
        for (int num : nums) {
            int squared = num * num;
            m[squared]++;
        }

        // Iterate through the map and add squared values to ans
        for (auto& x : m) {
            int squaredValue = x.first;
            int count = x.second;

            // Add the squared value to ans count times
            for (int i = 0; i < count; i++) {
                ans.push_back(squaredValue);
            }
        }

        return ans;
    }
};
