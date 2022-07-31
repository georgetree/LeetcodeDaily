class NumArray {
public:
    vector<int> t;
    int inverseBit(int x){
        return x & (-x);
    }
    
    void updateTree(int x, int v){
        while(x < t.size()){
            t[x] += v;
            x += inverseBit(x); 
        }
    }
    
    int query(int x){
        int res = 0;
        while(x>0){
            res+=t[x];
            x -= inverseBit(x);
        }
        return res;
    }
    
    vector<int> n;
    NumArray(vector<int>& nums) {
        n = nums;
        t.resize(nums.size()+1,0);
        for(int i=0; i<nums.size(); i++){
            updateTree(i+1,nums[i]);
        }
    }
    
    void update(int index, int val) {
        updateTree(index+1,val-n[index]);
        n[index] = val;
     
    }
    
    int sumRange(int left, int right) {
        return query(right+1) - query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */