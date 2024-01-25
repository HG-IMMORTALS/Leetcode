class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int text1L=text1.size(),text2L=text2.size();
        int dp[text1L+1][text2L+1];
        memset(dp,0,sizeof dp);
        for (int i=1;i<=text1L;++i)
        {
            for (int j=1;j<=text2L;++j)
            {
                if (text1[i-1]==text2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[text1L][text2L];
    }
};