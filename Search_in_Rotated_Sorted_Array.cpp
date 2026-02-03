class Solution {
    int findPivot(vector<int>& nums){
        int l = 0, r = nums.size() - 1;

        while(l < r){
            int m = (l + r) / 2;
            if(nums[m] > nums[r])
                l = m + 1;
            else
                r = m;
        }
        return l;   // important
    }

    int bs(vector<int>& nums, int l, int r, int target){
        while(l <= r){
            int m = (l + r) / 2;
            if(nums[m] == target) return m;
            if(nums[m] < target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums);

        if(target >= nums[pivot] && target <= nums[n-1])
            return bs(nums, pivot, n-1, target);
        else
            return bs(nums, 0, pivot-1, target);
    }
};
