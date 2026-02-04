class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        int prev = nums[0], prev2 = max(nums[0],nums[1]);
        for (int i = 2; i < nums.size(); ++i){
            int cur = max(prev+nums[i], prev2);
            prev = prev2;
            prev2 = cur;
        }
        return prev2;
    }
};