class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        while (idx < s.size() && s[idx]==' ')idx++;
        bool negative = s[idx]=='-' ? true : false;
        if (s[idx]=='-' || s[idx]=='+') idx++;
        long long ans = 0;
        while (idx < s.size()){
            if (!(s[idx]>='0' && s[idx]<='9')) break;
            int cur = s[idx]-'0';
            if (!negative && (ans > (INT_MAX - cur) / 10)) return INT_MAX;
            else if (ans > ((long long)INT_MAX + 1 - cur) / 10) return INT_MIN;
            ans = ans * 10 + cur;
            idx++;
        }
        return negative ? -ans : ans;
    }
};