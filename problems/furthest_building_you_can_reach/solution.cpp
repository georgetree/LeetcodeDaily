class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>q;
        for(int i=0; i<heights.size()-1; i++){
            int t = heights[i+1] - heights[i];
            if(t>0) q.push(-t);
            if(q.size()>ladders){
                bricks += q.top();
                q.pop();
            }
            if(bricks<0) return i;
        }
        return heights.size()-1;
    }
};