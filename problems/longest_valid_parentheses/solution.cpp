class Solution {
public:
    //最后一个没有被匹配的右括号的下标
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        stack<int> st;
        st.push(-1);
        int res = 0;
        for(int i=0; i<s.size(); ++i){
             if(s[i]==')'){
                 st.pop();
                 if(st.empty())
                    st.push(i);
                 else{
                     res = max(res,i-st.top()); 
                 }   
             }
             else
                 st.push(i);
        }
        return res;
    }
};