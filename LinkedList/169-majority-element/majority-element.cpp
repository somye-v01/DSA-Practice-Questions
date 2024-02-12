class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = 0;
        int count = 0;
        for(auto num : nums){
            if(count == 0){
                count++;
                x = num;
            }
            else if(num == x){
                count++;
            }
            else{ //num != x;
            count--;
            }
        }
        //actually n/2 se bigger he ke nahi
        
        count = 0;
        for(auto num : nums){
            if(num==x){
                count++;
            }
        }
        int n = nums.size();
        if(count > n/2){
            return x;
        }
        return 0;
    }
};