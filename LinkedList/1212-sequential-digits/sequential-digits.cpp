class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string str = "123456789";
        // int i = 0;
        // int j = i+1;
        // while(i<str.size()){
        //     string num = str.substr(i,j-i+1);
        //     cout << num <" ";
        //     j++;
        // }
        for(int i = 0; i < str.size(); i++){
            for(int j = i+1; j < str.size(); j++){
                string subnum = str.substr(i,j-i+1);
                // cout << subnum << " ";
                int num = stoi(subnum);
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
            }
        }
    sort(ans.begin(),ans.end());
    return ans;
    }
};