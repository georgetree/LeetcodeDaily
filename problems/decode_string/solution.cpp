class Solution {
public:
    string decodeString(string s) {
        stack<pair<int,string>> st;
        string num;
        string res;
        for(auto c:s){
            if (c == '[') {
                st.push({stoi(num),res});
                num = "";
                res = "";
            }
            else if(c == ']'){
                string t = res;
                auto[time,cur] = st.top(); st.pop();
                for(int i=1; i<time; i++)
                    res += t;
                res = cur + res;
            }
            else if(isdigit(c)) num += c;
            else if(isalpha(c)) res += c;
        }
        
        return res;
    }
};