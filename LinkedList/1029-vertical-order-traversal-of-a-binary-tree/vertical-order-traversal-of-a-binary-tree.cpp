/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void helper(TreeNode* root, vector<vector<int>>& ans){
        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode*, pair<int, int>>> q; // level, vertical
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            auto node = top.first;
            m[top.second.first][top.second.second].insert(node->val);

            if (node->left) {
                q.push({node->left, {top.second.first - 1, top.second.second + 1}});
            }
            if (node->right) {
                q.push({node->right, {top.second.first + 1, top.second.second + 1}});
            }
        }

        for (auto& it : m) {
            vector<int> temp;
            for (auto& i : it.second) { // iterate over the map inside the unordered_map
                for (int val : i.second) { // iterate over the multiset inside the map
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root,ans);
        return ans;
    }
};