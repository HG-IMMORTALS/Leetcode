class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            int val = nums[index];
            if(val < 0) {
                res.push_back(index + 1);
            } else {
                nums[index] = -nums[index];
            }
        }
        return res;
    }
};