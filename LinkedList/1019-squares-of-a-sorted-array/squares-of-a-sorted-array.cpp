class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> temp;
        vector<int> ans;
        bool flag = false;
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]<0){
                temp.push_back(nums[i]);
                // cout << nums[i] << " pushed in temp"<<endl;
            }
            else{
                if(flag == false){
                    reverse(temp.begin(),temp.end());
                    flag = true;
                //     for(auto x : temp){
                //     // cout << x << " ";
                // }
                }
                // cout << endl;
                while(j < temp.size() && abs(temp[j]) < nums[i]){
                    // cout << temp[j]*temp[j] <<" pushed in ans";
                    // cout << endl;
                    ans.push_back(temp[j]*temp[j]);
                    j++;
                }
                // cout << "value of i here is "<<i<<endl;
                ans.push_back(nums[i]*nums[i]);
                //  cout << nums[i]*nums[i] <<" pushed in ans";
                //  cout << endl;
            }
        }  
        if(flag==false) reverse(temp.begin(),temp.end());
        while (j < temp.size()) {
            ans.push_back(temp[j] * temp[j]);
            j++;
        }
        return ans;
    }
};