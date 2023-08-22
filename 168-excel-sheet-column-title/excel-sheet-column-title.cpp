class Solution {
public:
    string convertToTitle(int n) {
        string sol;
        char temp;
        while(n)
        {
            n-=1;
            temp='A'+n%26;
            sol=temp+sol;
            n/=26;
        }
        return sol;
    }
};