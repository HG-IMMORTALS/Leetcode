// class Solution {
// public:
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         int s=0;
//         long p=1;
//         int cnt=0; 
//         for(int e=0;e<nums.size();e++){
//             p*=nums[e];
//            while(p>=k && s<nums.size()){
//                p=p/nums[s];
//                 s++;
//               }
//            if(p<k) cnt+=e-s+1;
//       }
//     return cnt;
//     }
// };

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size() ; 
        int ans = 0 ; 
        if(k<=1){
           return 0 ; 
        }
        long long pro = 1 ; 
        int j = 0 ; 
        for(int i =0 ; i<n ; i++){
            pro *= nums[i] ; 
            while(pro>=k){
              pro/= nums[j] ; 
              j++ ; 

            }
            if(pro<k){
                ans += i-j+1 ;
            }
        }

        return ans ; 

    }
};