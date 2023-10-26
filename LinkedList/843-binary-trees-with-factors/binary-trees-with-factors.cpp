class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        map<int, long long int> m;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            m.insert({arr[i], 1});
        }
        for (int i = 1; i < arr.size(); i++)
        {
            auto it2 = m.find(arr[i]);
            long long int count = 0;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0)
                {
                    auto it = m.find(arr[i] / arr[j]);
                    auto it1 = m.find(arr[j]);
                    if (it != m.end())
                        count += (it->second) * (it1->second);
                }
            }
            it2->second += count;
        }
        long long int ans = 0;
        for (auto x = m.begin(); x != m.end(); x++)
            ans += x->second;
        return ans % 1000000007;
    }
};