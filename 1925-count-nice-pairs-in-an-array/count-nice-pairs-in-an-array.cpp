class Solution {
public:
   int rev(int n ){
       int x = 0 ; 
       while(n){
           x = x*10 + n%10;
           n = n/10;
       }
       return x; 
   }
    int countNicePairs(vector<int>& nums) {
        int res = 0; 
        for(auto &x:nums)
         x = x - rev(x);
         unordered_map<int,int> m ; 

         for(int i= 0 ; i<nums.size();i++){
             if(m.find(nums[i])!=m.end())
             res = (res + m[nums[i]])%1000000007;
             m[nums[i]]++;
         }
        return res;  
    }
};