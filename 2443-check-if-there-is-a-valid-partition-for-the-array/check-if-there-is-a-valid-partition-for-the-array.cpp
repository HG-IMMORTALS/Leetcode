class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return false;
        bool dp[3]={true,false,n>1?(nums[0]==nums[1]):false};
        for(int i=2;i<n;i++)
        {
            bool current=false;
        if(nums[i]==nums[i-1]&&dp[1]) current=true;
        else if(i-2>=0 && nums[i]==nums[i-1] && nums[i]==nums[i-2] &&dp[0]) current=true;
        else if (i-2>=0 && nums[i]-nums[i-1]==1 && nums[i-1]-nums[i-2]==1 && dp[0]) {
           current=true; 
        }
        dp[0]=dp[1];
        dp[1]=dp[2];
        dp[2]=current;
        }
        return dp[2];
    }
};