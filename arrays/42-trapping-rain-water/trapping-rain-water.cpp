class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n);
        vector<int> right_max(n);
        vector<int> ans(n);

        int count_left = 0;
        int count_right = 0;
        for(int i = 0; i < n; i++){
            count_left = max(count_left, height[i]);
            left_max[i] = count_left;
        }
        for(int i = n - 1; i >= 0; i--){
            count_right = max(count_right, height[i]);
            right_max[i] = count_right;
        }
        for(int i = 0; i < n; i++){
            int sol = min(right_max[i], left_max[i] ) - height[i];
            ans[i] = sol;
        }

        int count = 0;
        for(int i= 0; i < n; i++){
            count += ans[i];
        }

        return count;
    }
};