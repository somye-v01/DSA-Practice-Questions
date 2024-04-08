class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int>st;
        int cnt = 0;
        int size = students.size();
        for(int i = sandwiches.size()-1; i >= 0; i--){
            st.push(sandwiches[i]);
        }
        queue<int>q;
        for(auto x : students){
            q.push(x);
        }
        while(cnt < size && !q.empty()){
            if(q.front()==st.top()){
                q.pop();
                st.pop();
                cnt = 0;
            }
            else{
                // if(size == cnt){
                //     return cnt;
                // }
                int topst = q.front();
                q.pop();
                q.push(topst);
                cnt++;
            }
        }
        return q.size();
    }
};