class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>sol(1,1);
        long long prev=1;
        for(int k=1;k<=rowIndex;k++)
        {
            long long next_val=prev*(rowIndex-k+1)/k;
            sol.push_back(next_val);
            prev=next_val;
        }
        return sol;
    }
};