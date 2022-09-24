class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        for(string t: tokens){
            if(t=="+"){
                long i = stol(st.top());
                st.pop();
                long j = stol(st.top());
                st.pop();
                st.push(to_string(j + i));
            }
            else if(t=="-"){
                long i = stol(st.top());
                st.pop();
                long j = stol(st.top());
                st.pop();

                st.push(to_string(j - i));
            }
            else if(t=="*"){
                long i = stol(st.top());
                st.pop();
                long j = stol(st.top());
                st.pop();
                st.push(to_string(j * i));
            }         
            else if(t=="/"){
                long i = stol(st.top());
                st.pop();
                long j = stol(st.top());
                st.pop();
                st.push(to_string(j / i));
            
            }
            else st.push(t);
        }
        
        return stoi(st.top());
    }
};