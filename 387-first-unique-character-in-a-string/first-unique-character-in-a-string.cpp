class Solution {
public:
    int firstUniqChar(string s) {
    const int MAX_CHARS = 26;
    int freq[MAX_CHARS] = {0}; 
    int len = s.length();
    for(int i = 0; i < len; i++) {
        freq[s[i] - 'a']++; 
    }
    for(int i = 0; i < len; i++) {
        if(freq[s[i] - 'a'] == 1) { 
            return i;
        }
    }
    return -1;
}

};