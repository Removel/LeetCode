class Solution {
	public:
		double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
			if (nums1.size() > nums2.size()) {
				swap(nums1, nums2);
			}
			int m = nums1.size();
			int n = nums2.size();
			int left = 0, right = m;
			while (left <= right) {
				int i = (left + right) / 2;
				int j = (m + n + 1) / 2 -
				        i; //此处设计很妙：和为偶数时，左边个数即使和加了1也不影响，和为奇数时，加了1正好是的左边的个数是右边的个数加一
				int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
				int right1 = (i == m) ? INT_MAX : nums1[i];
				int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
				int right2 = (j == n) ? INT_MAX : nums2[j];
				if (left1 <= right2 && left2 <= right1) {
					if ((m + n) % 2 == 1) {
						return max(left1, left2);
					}
					return (max(left1, left2) + min(right1, right2)) / 2.0;
				} else if (left1 > right2) {
					right = i - 1;
				} else {
					left = i + 1;
				}
			}
			return 0;
		}
};