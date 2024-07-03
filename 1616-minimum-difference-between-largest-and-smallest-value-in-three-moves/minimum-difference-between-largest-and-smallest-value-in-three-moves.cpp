class Solution {
public:
   int minDifference(vector<int>& nums) {
	int n = nums.size();
	if(n < 5)
		return 0;
	partial_sort(nums.begin(), nums.begin() + 4, nums.end());
    partial_sort(nums.rbegin(), nums.rbegin() + 4, nums.rend(), greater<int>());
	int min_diff = INT_MAX;
	for(int i = 0, j = n - 4; i < 4; ++i, ++j)
		min_diff = min(min_diff, nums[j] - nums[i]);
	return min_diff;
}
};