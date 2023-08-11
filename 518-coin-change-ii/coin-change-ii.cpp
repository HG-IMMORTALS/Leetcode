// class Solution {
// public:
    
//     int coinChange(vector<int>& coins,int n,int amount)
//     {
//         if(n==0)
//             return 0;
//         if(amount==0)
//         {
//             return 1;
//         }
//         if(coins[n-1]>amount)
//         {
//             return coinChange(coins,n-1,amount);
//         }
//         return coinChange(coins,n,amount-coins[n-1])+coinChange(coins,n-1,amount);
//     }
    
//     int change(int amount,vector<int>& coins) {
//         int n=coins.size();
//         if(amount==0) 
//         {
//             return 1;
//         }
//         if(n==0)
//             return 0;
//         return coinChange(coins,n,amount);
        
//     }
// };
// class Solution {
// public:
//     int recursion(int w,vector<int>& wt,int n)
//     {
//         if (n==0||w==0)
//             return w==0?1:0;
        
//         if (wt[n-1]>w)
//             return recursion(w,wt,n-1);
//         else
//             return recursion(w,wt,n-1)+recursion(w-wt[n-1],wt,n);
//     }
    
//     int change(int amount,vector<int>& coins) 
//     {
//         return recursion(amount,coins,coins.size());    
//     }
// };
class Solution {
public:
    int change(int amount,vector<int>& coins) {
        vector<int>dp(amount+1,0);
        dp[0]=1;
        
        for (int coin:coins) {
            for (int j=coin;j<=amount;j++) 
            {
                dp[j]+=dp[j-coin];
            }
        }
        
        return dp[amount];
    }
};