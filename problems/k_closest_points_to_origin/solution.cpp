class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](vector<int> &a,vector<int> &b){
            return pow(a[0],2)+pow(a[1],2) > pow(b[0],2)+pow(b[1],2);
        };
            
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> q(cmp);
        for(auto &point:points){
            q.push(point);
        }
        vector<vector<int>> res;
        for(int i=0; i<k; i++){
            cout << q.top()[0] << " ";
            res.push_back(q.top());
            q.pop();
        }
            
        return res;
    }
};