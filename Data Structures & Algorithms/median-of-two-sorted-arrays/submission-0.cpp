class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n = nums1.size(), m = nums2.size();
        int total = n + m, half = total / 2;
        int l = 0, r = n;
        while (l <= r) {
            int i = l + (r - l) / 2;//mid
            int j = half - i;
            // Boundary values
            int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int right1 = (i == n) ? INT_MAX : nums1[i];
            int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2 = (j == m) ? INT_MAX : nums2[j];
            if (left1 <= right2 && left2 <= right1) {
                if (total % 2 == 1) {
                    return min(right1, right2);
                }
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            else if (left1 >  right2) {
                r = i - 1;
            }
            else {
                l = i + 1;
            }
        }
        return 0.0;
    }
};