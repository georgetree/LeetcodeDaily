class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int min = to_string(low).size();
        int max = to_string(high).size();
        string dig = "123456789";
        for(int i = min; i<=max; i++){
            for(int j=0; j<10-i;j++){
                int t = stoi(dig.substr(j,i));
                if(t >= low && t <= high) res.push_back(t);
            }
        }
        return res;
    }
};