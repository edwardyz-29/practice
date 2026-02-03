class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();
        while (i<n){
            if (i<n-1 && intervals[i][1] < intervals[i+1][0]) ans.push_back(intervals[i]);
            else {
                vector<int>merge = intervals[i];
                while (i<n-1 && merge[1] >= intervals[i+1][0]){
                    merge[0] = min(merge[0],intervals[i+1][0]);
                    merge[1] = max(merge[1],intervals[i+1][1]);
                    ++i;
                }
                ans.push_back(merge);
            }
            ++i;
        }
        return ans;
    }
};