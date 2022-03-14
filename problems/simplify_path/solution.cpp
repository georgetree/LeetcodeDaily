class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string res, t;
        stringstream ss(path);

        while(getline(ss, t, '/')){
            if(t==".."){
                if(!st.empty())
                    st.pop();
            }      
            else if(!t.empty() && t!="."){
                st.push(t);
            }
        }
        while(!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }
            
        return res.empty() ? "/" : res;
    }
};