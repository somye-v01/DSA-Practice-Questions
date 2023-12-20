class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        priority_queue<int,vector<int>,greater<int>> pq; 
        for(auto x : prices){
            pq.push(x);
        }
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        return (money-(min1+min2)>=0) ? money - (min1+min2) : money;
    }
};