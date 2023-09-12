class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // unordered_map<int,int> m1;
        // unordered_map<int,int> m2;
        // for(auto x : nums1){
        //     m1[]
        // }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> ans;
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()){
        if(nums1[i]==nums2[j]){
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i]<nums2[j]){
            i++;
        }
        else if(nums1[i] > nums2[j]){
            j++;
        }

        }
        return ans;
    }

};