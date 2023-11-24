class Solution {
public:
    int maxCoins(vector<int>& piles) {
        //pair up largest element, second largest element and the smallest element
        sort(piles.begin(),piles.end());
        int n = piles.size();
        for(auto x : piles){
            cout << x << " ";
        }
        int sum = 0;
        // for(int i = 1; i < n; i+=3){
        //     sum+=piles[i];
        // }
        //2 pointer, i at start, j at end
        int i = 0;
        int j = n-1;
        while(j>i){
            j--;
            sum+=piles[j];
            j--;
            i++;
        }
        return sum;
    }
};