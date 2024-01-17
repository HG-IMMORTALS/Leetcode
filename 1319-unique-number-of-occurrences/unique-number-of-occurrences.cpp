class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
  unordered_map<int, int> map;
        set<int> set;
        for(auto p : arr) map[p]++;
        for(auto& p : map){
            if(set.find(p.second) != set.end())
                return false;
            else
                set.insert(p.second);
        }
        return true;
    }
};