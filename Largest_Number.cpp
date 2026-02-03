class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        arr.reserve(nums.size());
        for (int i : nums) arr.push_back(to_string(i));
        sort(arr.begin(),arr.end(), [](string &a, string&b) {return a+b>b+a;});
        if (!arr.empty() && arr[0]=="0") return "0";
        string temp;
        for (string&s : arr) temp+=s;
        return temp;
    }
};