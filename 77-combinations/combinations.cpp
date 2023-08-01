class Solution {
public:
  vector<vector<int>>sol;
    
    void solve(int s,int n,int k,vector<int>& temp) {
        if(k==0)
				{
            sol.push_back(temp);
            return;
        }
        
        if(s>n)
            return;
        temp.push_back(s);
        solve(s+1,n,k-1,temp);
        temp.pop_back();
        solve(s+1,n,k,temp);
    }
    
    vector<vector<int>>combine(int n,int k) 
		{
        vector<int>temp;
        solve(1,n,k,temp);
        return sol;
		}
};