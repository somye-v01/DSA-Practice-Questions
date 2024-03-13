class Solution {
public:
    int pivotInteger(int n) {
        int sum = (n*(n+1))/2; //42
        // cout << "val of sum here is: "<<sum<<endl;
        int temp = 0;
        int ans = -1;
        for(int i = 1; i <= n; i++){
            temp+=i;
            // cout<<"val of temp here is: "<<temp<<endl;
            if(temp==(sum-temp+i)){
                return i;
            }
        }
        return ans;
    }
};