class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        m[0]=-1;
        int sum=0, ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) sum+=1;
            else sum-=1;
            if(m.find(sum)!=m.end()){
                if(ans<i-m[sum]){
                    ans = i-m[sum];
                }
            }else{
                m[sum]=i;
            }
        }
        return ans;
    }
};