class Solution {
public:
    int maxCoins(vector<int>& piles) {
        //pair up largest element, second largest element and the smallest element
        sort(piles.begin(),piles.end());
        int n = piles.size();
        
        int sum = 0;
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