class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); //-2,-1,0,0,1,2
        int n = nums.size(); //5
        vector<vector<int>>ans;
        for (int i = 0; i < n-3; ++i){
            if (i && nums[i]==nums[i-1]) continue;
            for(int j = i+1; j < n-2; ++j){
                if ((j > i + 1) && nums[j]==nums[j-1]) continue;
                int k = j+1, r = n-1;
                while (k<r){
                    long sum = 1L*nums[i]+nums[j]+nums[k]+nums[r];
                    if (sum<target) k++;
                    else if (sum>target) r--;
                    else {
                        ans.push_back({nums[i],nums[j],nums[k],nums[r]});
                        k++;
                        r--;
                        while (k<r && nums[k]==nums[k-1]) ++k;
                    }
                }
                
            }
        }
        return ans;
        
        
    }
};