class Solution {
public:
    int numMusicPlaylists(int n,int goal,int k) 
    {
        const int MOD=1e9+7;
        vector<vector<long long>>dp(2,vector<long long>(n+1,0));
        dp[0][0]=1;
        for(int i=1;i<=goal;i++)
        {
            dp[i%2][0]=0;
            for(int j=1;j<=min(i,n);j++)
            {
                dp[i%2][j]=dp[(i-1)%2][j-1]*(n-(j-1))%MOD;
                if(j>k)
                dp[i%2][j]=(dp[i%2][j]+dp[(i-1)%2][j]*(j-k))%MOD;
            }
        }
        return dp[goal%2][n];
    }
};

// class Solution {
// public:
    
    // int numMusicPlaylists(int n, int L, int k) {
    //     const int mod=100000007;
    //     vector<vector<long long>>dp(1+n,vector<long long>(1+L,0LL));
    //     dp[1][1]=1;
    //     for(int i=2;i<=n;++i)
    //     {
    //         dp[i][i]=(dp[i-1][i-1]*i)%mod;
    //     }
    //     for(int N=1;N<=n;++n)
    //     {
    //         for(int l=n+1;l<=L;++l)
    //         {
    //             dp[n][l]=((dp[n][l-1]*((n-k)>0?(n-k):0))%mod+(dp[n-1][l-1]*n)%mod)%mod;
    //         }
    //     }
    //     return dp[n][L];
    // }
// };