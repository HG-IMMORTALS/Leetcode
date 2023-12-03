class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<int> occ[26];
        for (int i = 0 ; i < 26; i++) {
            occ[i].push_back(-1);
        }
        for (int i = 0 ; i < n ; i++) {
            occ[s[i] - 'A'].push_back(i);
        }
        for (int i = 0 ; i < 26 ; i++) {
            occ[i].push_back(n);
        }
        int cnt = 0 ;
        for (int i = 0 ; i < 26 ; i++) {
            for (int j = 1 ; j < (occ[i].size() - 1) ; j++) {
                cnt += (occ[i][j] - occ[i][j - 1]) * (occ[i][j + 1] - occ[i][j]);
            }
        }
        return cnt ; 
    }
};