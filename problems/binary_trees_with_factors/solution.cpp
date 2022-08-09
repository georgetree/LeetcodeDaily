class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,long>m;
        long res = 0;
        int n = arr.size();
        int M = 1e9+7;
        for(auto const &i:arr)
            m[i] = 1;
        sort(arr.begin(),arr.end());
   
        for(int i=1; i<n; i++){
            long count = 0;
            for(int j=0; j<i; j++){
                int temp = arr[i]/arr[j];
                if(arr[i] % arr[j] == 0 && m.find(temp)!=m.end())
                    count+=(m.find(arr[j])->second * m.find(arr[i]/arr[j])->second) % M;
            }
            m[arr[i]] += count;
        }
        for(auto &i : m)
            res+=i.second;
        return res%M;
    }
};