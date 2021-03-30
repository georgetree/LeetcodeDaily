class Solution {
public:
    struct cmp {
        bool operator()(pair<string,int> &a,pair<string, int>& b) {
            if(a.second != b.second)
                return a.second < b.second;
            return a.first > b.first;
        } 
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> countmap;
        for(int i=0; i<words.size(); i++){
            countmap[words[i]]++ ;
        }
        priority_queue<pair<string,int>, vector<pair<string,int>>, cmp> maxHeap;
        for(const auto &v:countmap){
            maxHeap.push(v);
        }
        vector<string> result;
        for(int i=0; i<k; i++){
            result.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return result;
    }
};