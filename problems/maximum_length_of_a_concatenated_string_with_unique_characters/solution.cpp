class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> v{bitset<26>{}};
        int res = 0;
        
        for(auto &a: arr){
            bitset<26> bs;
            for(auto &c:a){
                bs.set(c-'a');
            }
            if(bs.count() < a.size()) continue; //代表有重複字串跳過
            
            for(int i=0; i<v.size(); i++){
                auto t = v[i];
                if((t & bs).any()) continue; //表示有重複
                res = max(res,(int)t.count()+(int)bs.count());
                v.push_back(t|bs);
            }
        }
        return res;
        
    }
};