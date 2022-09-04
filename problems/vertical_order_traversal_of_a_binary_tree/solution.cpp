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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int, map<int, vector<int>>> m;
        queue<pair<TreeNode*, vector<int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            TreeNode *node = t.first;
            int x = t.second[0], y = t.second[1];
            m[x][y].push_back(node->val);
            if (node->left) q.push({node->left, {x - 1, y + 1}});
            if (node->right) q.push({node->right, {x + 1, y + 1}});
        }
        for (auto &a : m) {
            vector<int> col;
            for (auto &it : a.second) {
                sort(it.second.begin(), it.second.end());
                col.insert(col.end(), it.second.begin(), it.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
};
