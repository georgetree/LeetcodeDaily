class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
            priority_queue<int> MaxHeap(stones.begin(), stones.end());
            while(MaxHeap.size()>1){
                int a = MaxHeap.top();
                MaxHeap.pop();
                int b = MaxHeap.top();
                MaxHeap.pop();
                if(abs(a-b)!=0)
                    MaxHeap.push(abs(a-b));
            }
            if(!MaxHeap.empty())
                return MaxHeap.top();
            else return 0;
    }
};