class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>>tp_group;
        vector<vector<int>>res;
        
        for(int i=0;i<groupSizes.size();i++)
        {
            int size=groupSizes[i];
            tp_group[size].push_back(i);
            
            if(tp_group[size].size()==size)
            {
                res.push_back(tp_group[size]);
                tp_group[size].clear();
            }
        }
        return res;
    }
};