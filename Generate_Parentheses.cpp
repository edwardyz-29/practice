class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string sub;
        dfs(0,0,n,sub,ans);
        return ans;
    }
    void dfs(int open, int closed, int n, string& sub, vector<string>&ans){
        if (open==n && closed == n){
            ans.push_back(sub);
            return;
        }
        if (open < n) {
            sub.push_back('(');
            dfs(open+1,closed,n,sub,ans);
            sub.pop_back();
        }
        if (closed < open) {
            sub.push_back(')');
            dfs(open,closed+1,n,sub,ans);
            sub.pop_back();
        }
    }
};