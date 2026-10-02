class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        // int ans = 0;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] == "*" or tokens[i] == "/" or tokens[i] == "+" or tokens[i] == "-"){
                int first = stoi(st.top());
                st.pop();
                int second =stoi(st.top());
                st.pop();
                // cout<<first<<" "<<second<<endl;
                int ans=0;
                if(tokens[i] == "+") ans= (first + second);
                if(tokens[i] == "-") ans= (second - first);
                if(tokens[i] == "*") ans= (first * second);
                if(tokens[i] == "/") ans= (second / first);
                // cout<<ans<<endl;
                st.push(to_string(ans));
            }
            else{
                st.push(tokens[i]);
            }
        }
        return stoi(st.top());
    }
};
