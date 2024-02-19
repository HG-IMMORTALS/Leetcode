class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i=0;i<=30;i++) 
        {
            int sol=pow(2,i);
            if(sol==n) return true;
        }
        return false;
    }
};