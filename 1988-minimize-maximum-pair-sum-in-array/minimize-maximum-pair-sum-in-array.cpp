class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left=0,right=nums.size()-1;
        int minMaxPairSum=INT_MIN;
        while(left<right)
        {
            int currpairsum=nums[left]+nums[right];
            minMaxPairSum=max(minMaxPairSum,currpairsum);
            left++;
            right--;
        }
        return minMaxPairSum;
    }
};