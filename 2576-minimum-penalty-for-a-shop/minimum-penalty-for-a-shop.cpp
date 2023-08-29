class Solution {
public:
    int bestClosingTime(string cust) {
         int yesc=0,noc=0;
         for(char c : cust)
            if(c=='Y')
                yesc++;
 
        int penal=0,mintime=INT_MAX,minpenal=INT_MAX;
        
        for(int i=0;i<=cust.length();i++)
        {
            penal=yesc+noc;
            if(penal<minpenal)
            {
                mintime=i;
                minpenal=penal;
            }
            if(i<cust.length() && cust[i] == 'N')
                noc++;
            if(i<cust.length() && cust[i] == 'Y')
                yesc--;
        }
        return mintime;
    }
};