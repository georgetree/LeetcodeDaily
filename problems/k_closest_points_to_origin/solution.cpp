class Solution {
public:
    struct cmp {
        bool operator()(vector<int> &a, vector<int> &b) {
             return a[0]*a[0]+a[1]*a[1] > b[0]*b[0]+b[1]*b[1];
        }  
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> minHeap;
        for(const auto &point:points){
            minHeap.push(point);
        }
        vector<vector<int>> result;
        for(int i=0; i<k; i++){
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        return result;
    }
};