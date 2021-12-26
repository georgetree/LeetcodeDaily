class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        typedef pair<int,vector<int>> tp;
        struct Order
        {
            bool operator()(tp const& a, tp const& b) const
            {
                return a.first > b.first;
            }
        };

        priority_queue<tp> min_heap;

        for(auto i: points){
            int t = 0;
            t = pow(i[0],2) + pow(i[1],2);
            min_heap.push(make_pair(t,i));
            if(min_heap.size()>k) min_heap.pop();
        }
        for(int i=0; i<k; i++){
            auto t = min_heap.top().second; min_heap.pop();
            res.push_back(t);
        }
        return res;
    }
};