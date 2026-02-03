class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size()+nums2.size();
        int prev = 0, cur = 0;
        auto p1 = nums1.begin();
        auto p2 = nums2.begin();
        for (int i = 0; i < (size/2)+1; ++i){
            prev = cur;
            if (p1==nums1.end()){
                cur = *p2;
                p2++;
            }
            else if (p2==nums2.end()){
                cur = *p1;
                p1++;
            }
            else if (*p1<=*p2){
                cur = *p1;
                p1++; 
            }
            else{
                cur = *p2;
                p2++;
            } 
        }
        return size&1 ? cur : (cur+prev)/2.0;
    }
};