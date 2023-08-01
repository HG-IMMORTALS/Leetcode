class Solution {
public:
  vector<vector<int>> combine(int n, int k) 
	{
    vector<vector<int>>sol;
		int j=0;
		vector<int>m(k, 0);
		while (j>=0)
    {
			m[j]++;
			if (m[j]>n) --j;
			else if (j==k-1) sol.push_back(m);
			else 
			{
			    ++j;
			    m[j]=m[j-1];
			}
		}
		return sol;
	}
};