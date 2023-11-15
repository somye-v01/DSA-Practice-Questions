class Solution {
public:
   int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    int n = arr.size();
    vector<int> count(n + 1, 0);

    for (int x : arr) {
        count[min(x, n)]++;
    }

    int maxEl = 0; 
    int i = 1;

    while (i <= n) {
        int freq = count[i];

        maxEl = min(maxEl + freq, i);
        i++;
    }

    return maxEl;
}
};