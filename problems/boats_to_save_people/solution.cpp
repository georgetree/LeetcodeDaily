class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.rbegin(),people.rend());
        int res = 0;
        for(int i=0, j= people.size()-1; i<=j; i++){
            if(people[i]+people[j] <= limit) j--;
            res++;
        }
        return res;
    }
};