class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> ans;
        for (string str : strs) {
            string sortedstr = str;
            sort(sortedstr.begin(), sortedstr.end()); // Sort 'sortedstr', not 'str'
            m[sortedstr].push_back(str); // Use 'sortedstr' as key and push 'str' into the vector
        }

        for (auto it = m.begin(); it != m.end(); ++it) {
            ans.push_back(it->second); // Push the vector of anagrams into 'ans'
        }
        
        return ans; // Return the grouped anagrams
    }
};