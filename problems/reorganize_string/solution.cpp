class Solution {
public:
    
    string reorganizeString(string S) {
        unordered_map<char,int> countmap;
        for(int i=0; i<S.size(); i++){
            countmap[S[i]]++ ;          
        } 
        priority_queue<pair<int,char>>maxHeap;
        int len = (S.size()+1)/2;
        for(const auto &v:countmap){
            if(v.second>len){
                return "";
            }
            maxHeap.push({v.second,v.first});
        }
        string result="";
        while(maxHeap.size()>1){
            pair<int,char> a = maxHeap.top();
            maxHeap.pop();
            result.push_back(a.second); 
            pair<int,char> b = maxHeap.top();
            maxHeap.pop();
            result.push_back(b.second);
            if(a.first>1)
                maxHeap.push({a.first-1,a.second});
            if(b.first>1)
                maxHeap.push({b.first-1,b.second});
        }
        if(maxHeap.size()==1){
            result+=(maxHeap.top().second);
            return result;
        }
        return result;
    }
};