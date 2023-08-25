class Solution {
public:
    bool interleave(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<int>> &dp)
    {
        if(k==s3.size()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool sol=false;
        if(i<s1.size() && s3[k]==s1[i]) sol=sol||interleave(s1,s2,s3,i+1,j,k+1,dp);
        if(j<s2.size() && s3[k]==s2[j]) sol=sol||interleave(s1,s2,s3,i,j+1,k+1,dp);
        return dp[i][j]=sol;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return interleave(s1,s2,s3,0,0,0,dp);
    }
};