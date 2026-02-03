class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));
        for (int i = 0; i < s.size(); ++i) dp[i][i] = true;
        int len = 1, st = 0;
        for (int length = 2; length < s.size()+1; ++length){
            for (int start = 0; start + length < s.size()+1; ++start){
                int end = start+length-1;
                if (s[start]==s[end]){
                    if (length==2){
                        if (length>len){
                            cout << "done" << endl;
                            st = start;
                            len = length;
                        }
                        dp[start][end]=true;
                    } else if (dp[start+1][end-1]){
                        
                        if (length>len){
                            st = start;
                            len = length;
                        }
                        dp[start][end]=true;
                    }
                }
            }
        }
        return s.substr(st,len);
    }
};