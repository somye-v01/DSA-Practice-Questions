class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int area = 0;
        while ( i < j){
            int h = min(height[i],height[j]);
            int ans = h * (j - i);
            area = max(area,ans);
            while(height[i] <= h && i < j){
                i++;
            }
            while(height[j] <= h && i < j){
                --j;
            }
        }
        return area;
    }
};