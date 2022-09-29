class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>>> q;
        for(auto &a:arr){
            q.push({abs(a-x),a});
        }
        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(q.top().second);
            q.pop();
        }
        sort(res.begin(),res.end());
        return res;
            
    }
};