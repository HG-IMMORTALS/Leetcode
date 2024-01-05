class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
    vector<int>ans;
    for (int a:nums)
        if (ans.size()==0 || a>ans.back()) ans.push_back(a);
        else *lower_bound(ans.begin(),ans.end(),a)=a;
    return ans.size();
    }
};