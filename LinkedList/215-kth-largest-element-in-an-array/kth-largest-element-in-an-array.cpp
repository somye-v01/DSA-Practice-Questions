class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //sort using maxheap
        priority_queue<int> pq;
        for(auto x : nums){
            pq.push(x); //will sort it
        }
        // k-1 times pop
        if(k==1) return pq.top();
        for(int i = 0; i < k - 1; i++){
            pq.pop();
        }
        return pq.top();
    }
};