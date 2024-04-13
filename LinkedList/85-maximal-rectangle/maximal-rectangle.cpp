class Solution {
public:

    vector<int> getPrevSmaller(vector<int>& height){
        int n = height.size();
        vector<int> ans(n);
        stack<int> st;
        // st.push(-1);
        for(int i = 0 ; i < n ; i++){
            if(st.empty()){
                ans[i] = -1;
            }
            else{
            while(!st.empty() && height[i] <= height[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> getNextSmaller(vector<int>& height){
        int n = height.size();
        vector<int> ans(n);
        stack<int> st;
        // st.push(n);
        for(int i = n-1 ; i >= 0 ; i--){
            if(st.empty()){
                ans[i] = n;
            }
            else{
            while(!st.empty() && height[i] <= height[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = n;
            }
            else{
                ans[i] = st.top();
            }
            }
            st.push(i);
        }
        return ans;
    }

    int getMaxArea(vector<int>& height){
        vector<int> prevsmall = getPrevSmaller(height);
        vector<int> nextsmall = getNextSmaller(height);
        int area = 0;
        for(int i = 0; i < height.size(); i++){
            int w = nextsmall[i] - prevsmall[i] - 1;
            int l = height[i];
            area = max(area, w*l);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        //calculating heights first
        vector<int> height(m);
        for(int i = 0; i < m; i++){
            height[i] = matrix[0][i] - '0';
        }
        int maxArea = getMaxArea(height);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '0'){
                    height[j] = 0;
                }
                else{
                    height[j]+=1;
                }
            }
            maxArea = max(maxArea, getMaxArea(height));
        }
        return maxArea;
    }
};