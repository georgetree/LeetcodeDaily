class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res;
        stack<int> h;
        for(string i:ops){
            
            if(i=="+"){
                int t=0;
                int t2=0;
                t = h.top();
                h.pop();
                t2 = h.top();
                h.push(t);
                h.push(t2+t);
            }
            else if(i=="D"){
                h.push(h.top()*2);
            }
            else if(i=="C")
                h.pop();
            else{
                h.push(stoi(i));
            }
            
        }
        while(!h.empty()){
            res+=h.top();
            h.pop();
        }
        return res;
    }
};