class Solution {
public:
    int MOD = 1000000007;

    // Recursive
    int solve(int n, int absent, int late){
        if(n == 0) return 1;

        int A, L, P;
        A = L = P = 0;

        if(absent > 0){
            A = (solve(n-1, absent-1, 2)) % MOD;
        }

        if(late > 0){
            L = (solve(n-1, absent, late-1)) % MOD;
        }

        P = (solve(n-1, absent, 2)) % MOD;

        return (A + L + P) % MOD;
    }

    // Recursive + Memoization
    int solveMem(int n, int absent, int late, vector<vector<vector<int>>> &DP){
        if(n == 0) return 1;

        if(DP[n][absent][late] != -1) return DP[n][absent][late];

        int A, L, P;
        A = L = P = 0;

        if(absent > 0){
            A = (solveMem(n-1, absent-1, 2, DP)) % MOD;
        }

        if(late > 0){
            L = (solveMem(n-1, absent, late-1, DP)) % MOD;
        }

        P = (solveMem(n-1, absent, 2, DP)) % MOD;

        return DP[n][absent][late] = ((A + L) % MOD + P) % MOD;
    }

    // Tabulation
    int solveTab(int num){
        vector<vector<vector<int>>> DP(num+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int i=0; i<=1; i++){
            for(int j=0; j<=2; j++){
                DP[0][i][j] = 1;
            }
        }

        for(int n=1; n<=num; n++){
            for(int absent=0; absent <= 1; absent++){
                for(int late = 0; late <= 2; late++){
                    int A, L, P;
                    A = L = P = 0;

                    if(absent > 0){
                        A = DP[n-1][absent-1][2];
                    }

                    if(late > 0){
                        L = DP[n-1][absent][late-1];
                    }

                    P = DP[n-1][absent][2];

                    DP[n][absent][late] = ((A + L) % MOD + P) % MOD;
                } 
            }
        }

        return DP[num][1][2];
    }

    // Space optimised
    int solveSO(int num){
        vector<vector<int>> prev(2, vector<int>(3, 1));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for(int n=1; n<=num; n++){
            for(int absent=0; absent <= 1; absent++){
                for(int late = 0; late <= 2; late++){
                    int A, L, P;
                    A = L = P = 0;

                    if(absent > 0){
                        A = prev[absent-1][2];
                    }

                    if(late > 0){
                        L = prev[absent][late-1];
                    }

                    P = prev[absent][2];

                    curr[absent][late] = ((A + L) % MOD + P) % MOD;
                } 
            }

            prev = curr;
        }

        return prev[1][2];
    }

    int checkRecord(int n) {
        // return solve(n, 1, 2);
        return solveSO(n);
    }
};

