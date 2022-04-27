class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> root(n, -1);
        vector<vector<int>> g(n);
        for (auto &pair : pairs) {
            int x = find(root, pair[0]), y = find(root, pair[1]);
            if (x != y) {
                root[x] = y;
            }
        }
        for (int i = 0; i < n; ++i) {
            g[find(root, i)].push_back(i);
        }
        for (auto &a : g) {
            string t;
            for (int idx : a) t += s[idx];
            sort(t.begin(), t.end());
            for (int i = 0; i < a.size(); ++i) {
                s[a[i]] = t[i];
            }
        }
        return s;
    }
    int find(vector<int>& root, int i) {
        return root[i] < 0 ? i : root[i] = find(root, root[i]);
    }

 
};