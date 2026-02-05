class Solution {
public:
    bool isOp(string c){
        if (c.size()>1) return false;
        return c[0] == '+' || c[0] == '-' || c[0]=='/' || c[0]=='*';
    }
    int operate(int a, int b, char op){
        if (op=='+') return a+b;
        if (op=='-') return a-b;
        if (op=='/') return a/b;
        return a*b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for (int i = 0; i < tokens.size(); ++i){
            if (!isOp(tokens[i]))st.push(stoi(tokens[i]));
            else {
                int top = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();
                st.push(operate(top2,top,tokens[i][0]));
            }
        }
        return st.top();
    }
};