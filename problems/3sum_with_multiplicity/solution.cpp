class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        long res = 0, M = 1e9 + 7;
        unordered_map<int, long> numCnt;
        for (int num : A) ++numCnt[num];
        for (auto a : numCnt) {
            for (auto b : numCnt) {
                int i = a.first, j = b.first, k = target - i - j;
                if (!numCnt.count(k)) continue;
                if (i == j && j == k) {
                    res += numCnt[i] * (numCnt[i] - 1) * (numCnt[i] - 2) / 6;  
                } else if (i == j && j != k) {
                    res += numCnt[i] * (numCnt[i] - 1) / 2 * numCnt[k];
                } else if (i < j && j < k) {
                    res += numCnt[i] * numCnt[j] * numCnt[k];
                }
            }
        }
        return res % M;
    }
};
